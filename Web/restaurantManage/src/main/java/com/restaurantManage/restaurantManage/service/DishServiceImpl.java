package com.restaurantManage.restaurantManage.service;

import com.restaurantManage.restaurantManage.DAO.*;
import com.restaurantManage.restaurantManage.dto.DishOrderDTO;
import com.restaurantManage.restaurantManage.dto.DishOrderRepository;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class DishServiceImpl implements DishService{

    private final DishRepository dishRepository;
    private final DishOrderDao dishOrderDao;
    private final DishOrderRepository dishOrderRepository;
    private final theTableRepository tableRepository;

    public DishServiceImpl(DishRepository dishRepository,DishOrderDao dishOrderDao,DishOrderRepository dishOrderRepository,
                           theTableRepository tableRepository) {

        this.dishRepository = dishRepository;
        this.dishOrderDao = dishOrderDao;
        this.dishOrderRepository = dishOrderRepository;
        this.tableRepository = tableRepository;
    }
    /*@Override
    public Dish GetDishByName(String id) {
        return dishRepository.findById(id).orElseThrow(RuntimeException::new);
    }*/

    @Override
    public List<Dish> GetAllDishes() {
        return dishRepository.findAll();
    }

    @Override
    public void dishOrder(String tableId, String dishName) {
        if(tableRepository.findById(tableId).isEmpty() || dishRepository.findById(dishName).isEmpty()){
            throw new IllegalArgumentException("tableId or dishName cannot be null or empty");
        }
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
