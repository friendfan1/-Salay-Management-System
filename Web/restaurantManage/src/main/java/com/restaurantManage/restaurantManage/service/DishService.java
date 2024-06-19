package com.restaurantManage.restaurantManage.service;

import com.restaurantManage.restaurantManage.DAO.Dish;
import com.restaurantManage.restaurantManage.DAO.DishOrder;
import com.restaurantManage.restaurantManage.dto.DishOrderDTO;
import org.springframework.data.repository.query.Param;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

public interface DishService {
//    Dish GetDishByName(String id);

    List<Dish> GetAllDishes();

//    List<DishOrder> GetAllDisherOrder();

    void dishOrder(String tableId, String dishName);

    @Transactional
    List<DishOrderDTO> findAllOrderByTableNum(String TableNum);
}
