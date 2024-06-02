package com.restaurantManage.restaurantManage.service;

import com.restaurantManage.restaurantManage.DAO.Dish;
import org.springframework.data.repository.query.Param;

import java.util.List;

public interface DishService {
    Dish GetDishByName(String id);

    List<Dish> GetAllDishes();

//    List<DishOrder> GetAllDisherOrder();

    void dishOrder(String tableId, String dishName);
}
