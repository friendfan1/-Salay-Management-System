package com.restaurantManage.restaurantManage.DAO;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.query.Procedure;
import org.springframework.data.repository.query.Param;

public interface DishOrderDao extends JpaRepository<DishOrder,DishOrderId> {

    @Procedure(value = "点菜")
    void orderDish(@Param("param1")String tableId, @Param("param2")String dishName);
}
