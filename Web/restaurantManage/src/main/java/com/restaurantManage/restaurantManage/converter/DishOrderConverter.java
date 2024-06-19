package com.restaurantManage.restaurantManage.converter;

import com.restaurantManage.restaurantManage.DAO.Dish;
import com.restaurantManage.restaurantManage.DAO.DishOrder;
import com.restaurantManage.restaurantManage.DAO.Person;
import com.restaurantManage.restaurantManage.dto.DishOrderDTO;
import com.restaurantManage.restaurantManage.dto.PersonDTO;

public class DishOrderConverter {
    public static DishOrderDTO converter(DishOrder dishOrder, Dish dish){
        DishOrderDTO dishOrderDTO = new DishOrderDTO();
        dishOrderDTO.setDishName(dishOrder.getDishName());
        dishOrderDTO.setState(dishOrder.getState());
        dishOrderDTO.setTime(dishOrder.getOrderTIme());
        dishOrderDTO.setPrice(dish.getPrice());
        dishOrderDTO.setDiscount(dish.getDiscount());
        return dishOrderDTO;
    }



}
