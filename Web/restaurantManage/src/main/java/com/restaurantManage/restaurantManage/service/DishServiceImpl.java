package com.restaurantManage.restaurantManage.service;

import com.restaurantManage.restaurantManage.DAO.Dish;
import com.restaurantManage.restaurantManage.DAO.DishOrder;
import com.restaurantManage.restaurantManage.DAO.DishOrderDao;
import com.restaurantManage.restaurantManage.DAO.DishRepository;
import com.restaurantManage.restaurantManage.dto.DishOrderDTO;
import com.restaurantManage.restaurantManage.dto.DishOrderRepository;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class DishServiceImpl implements DishService{

    private final DishRepository dishRepository;
    private final DishOrderDao dishOrderDao;
    private final DishOrderRepository dishOrderRepository;

    // 使用构造函数注入
    public DishServiceImpl(DishRepository dishRepository,DishOrderDao dishOrderDao,DishOrderRepository dishOrderRepository) {

        this.dishRepository = dishRepository;
        this.dishOrderDao = dishOrderDao;
        this.dishOrderRepository = dishOrderRepository;
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

    @Override
    public List<DishOrderDTO> findAllOrderByTableNum(String TableNum) {
        return dishOrderRepository.findAllOrderByTableNum(TableNum);
    }

    /*@Override
    public List<DishOrder> GetAllDisherOrder() {
        List<DishOrder>
        return null;
    }*/


}
