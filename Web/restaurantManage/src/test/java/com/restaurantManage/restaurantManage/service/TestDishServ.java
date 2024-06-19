package com.restaurantManage.restaurantManage.service;

import com.restaurantManage.restaurantManage.DAO.*;
import com.restaurantManage.restaurantManage.dto.DishOrderDTO;
import com.restaurantManage.restaurantManage.dto.DishOrderRepository;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;
import org.mockito.junit.jupiter.MockitoExtension;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;

import java.sql.Time;
import java.time.LocalTime;
import java.util.Arrays;
import java.util.List;
import java.util.Optional;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.mockito.ArgumentMatchers.anyString;
import static org.mockito.Mockito.*;

//@ExtendWith(MockitoExtension.class)
@SpringBootTest
public class TestDishServ {

    @MockBean
    private DishRepository dishRepository;

    @MockBean
    private DishOrderRepository dishOrderRepository;

    @MockBean
    private DishOrderDao dishOrderDao;

    @MockBean
    private theTableRepository tableRepository;

    @Autowired
    private DishServiceImpl dishService;


    /*@BeforeEach
    void setUp() {
        MockitoAnnotations.openMocks(this);
    }*/

    @Test
    public void testGetAllDishes() {
        Dish dish1 = new Dish();
        dish1.setId("Dish1");
        Dish dish2 = new Dish();
        dish2.setId("Dish2");

        when(dishRepository.findAll()).thenReturn(Arrays.asList(dish1, dish2));

        List<Dish> dishes = dishService.GetAllDishes();

        assertEquals(2, dishes.size());
        assertEquals("Dish1", dishes.get(0).getId());
        assertEquals("Dish2", dishes.get(1).getId());
    }

    @Test
    public void testDishOrder() {
        doNothing().when(dishOrderDao).orderDish(anyString(), anyString());

        // 调用实际方法
        assertThrows(IllegalArgumentException.class,()->dishService.dishOrder("Table1", "Dish1"));

        theTable table = new theTable();
        table.setTableId("Table1");
        Dish dish = new Dish();
        dish.setId("Dish1");
        when(tableRepository.findById(anyString())).thenReturn(Optional.of(table));
        assertThrows(IllegalArgumentException.class,()->dishService.dishOrder("Table1", "Dish1"));
        when(dishRepository.findById(anyString())).thenReturn(Optional.of(dish));

        dishService.dishOrder("Table1","Dish1");

        // 验证 dishOrderDao 是否被调用
        verify(dishOrderDao, times(1)).orderDish("Table1", "Dish1");
    }


    @Test
    public void testFindAllOrderByTableNum() {
        LocalTime time = LocalTime.now();
        DishOrderDTO orderDTO = new DishOrderDTO("Dish1",1,1,time,"state");

        when(dishOrderRepository.findAllOrderByTableNum("Table1")).thenReturn(Arrays.asList(orderDTO));

        List<DishOrderDTO> orders = dishService.findAllOrderByTableNum("Table1");
        assertEquals(1, orders.size());
        //assertEquals("A1", orders.get(0).getTableId());
        assertEquals("Dish1", orders.get(0).getDishName());
    }



}
