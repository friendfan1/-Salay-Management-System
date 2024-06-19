package com.restaurantManage.restaurantManage.Controller;

import com.restaurantManage.restaurantManage.DAO.Dish;
import com.restaurantManage.restaurantManage.dto.DishOrderDTO;
import com.restaurantManage.restaurantManage.service.DishService;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.setup.MockMvcBuilders;

import java.util.Arrays;
import java.util.List;

import static org.mockito.Mockito.*;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.model;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.view;

@WebMvcTest(DishController.class)
public class TestDishController {

    @Autowired
    private MockMvc mockMvc;

    @MockBean
    private DishService dishService;

    @Test
    public void testMenu() throws Exception {
        List<Dish> dishes = Arrays.asList(new Dish(), new Dish());
        when(dishService.GetAllDishes()).thenReturn(dishes);

        mockMvc.perform(get("/1/menu"))
                .andExpect(status().isOk())
                .andExpect(view().name("menu"))
                .andExpect(model().attributeExists("dishes"))
                .andExpect(model().attributeExists("tableNum"))
                .andExpect(model().attribute("dishes", dishes))
                .andExpect(model().attribute("tableNum", "1"));

        verify(dishService, times(1)).GetAllDishes();
    }

    @Test
    public void testOrderDish() throws Exception {
        mockMvc.perform(get("/1/menu/dish1"))
                .andExpect(status().is3xxRedirection())
                .andExpect(view().name("redirect:/{tableNum}/menu/dish1/success"));

        verify(dishService, times(1)).dishOrder("1", "dish1");
    }


    @Test
    public void testOrderSuccess() throws Exception {
        mockMvc.perform(get("/1/menu/dish1/success"))
                .andExpect(status().isOk())
                .andExpect(view().name("success"))
                .andExpect(model().attributeExists("tableNum"))
                .andExpect(model().attributeExists("dish"))
                .andExpect(model().attribute("tableNum", "1"))
                .andExpect(model().attribute("dish", "dish1"));
    }

    @Test
    public void testOrderedDishes() throws Exception {
        List<DishOrderDTO> dishOrders = Arrays.asList(new DishOrderDTO(), new DishOrderDTO());
        when(dishService.findAllOrderByTableNum("1")).thenReturn(dishOrders);

        mockMvc.perform(get("/1/menu/ordered"))
                .andExpect(status().isOk())
                .andExpect(view().name("ordered"))
                .andExpect(model().attributeExists("tableNum"))
                .andExpect(model().attributeExists("dishOrdered"))
                .andExpect(model().attribute("tableNum", "1"))
                .andExpect(model().attribute("dishOrdered", dishOrders));

        verify(dishService, times(1)).findAllOrderByTableNum("1");
    }
}
