package com.restaurantManage.restaurantManage.service;

import com.restaurantManage.restaurantManage.DAO.Dish;
import com.restaurantManage.restaurantManage.DAO.DishOrderDao;
import com.restaurantManage.restaurantManage.DAO.DishRepository;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class DishServiceImpl implements DishService{

    private final DishRepository dishRepository;
    private final DishOrderDao dishOrderDao;

    // 使用构造函数注入
    public DishServiceImpl(DishRepository dishRepository,DishOrderDao dishOrderDao) {

        this.dishRepository = dishRepository;
        this.dishOrderDao = dishOrderDao;
    }
    @Override
    public Dish GetDishByName(String id) {
        return dishRepository.findById(id).orElseThrow(RuntimeException::new);
    }

    @Override
    public List<Dish> GetAllDishes() {
        List<Dish> all = dishRepository.findAll();
        return all;
    }

    @Override
    public void dishOrder(String tableId, String dishName) {
        dishOrderDao.orderDish(tableId,dishName);
    }

    /*@Override
    public List<DishOrder> GetAllDisherOrder() {
        List<DishOrder>
        return null;
    }*/


}
