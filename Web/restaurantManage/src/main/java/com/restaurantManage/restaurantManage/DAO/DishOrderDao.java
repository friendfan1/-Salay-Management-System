package com.restaurantManage.restaurantManage.DAO;

import com.restaurantManage.restaurantManage.dto.DishOrderDTO;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.query.Procedure;
import org.springframework.data.repository.query.Param;

import java.util.List;

public interface DishOrderDao extends JpaRepository<DishOrder,DishOrderId> {

    @Procedure(value = "点菜")
    void orderDish(@Param("param1")String tableId, @Param("param2")String dishName);

    @Procedure(value = "查看已点菜Web")
    List<DishOrderDTO> getAllDishesOrderedByTableNum(@Param("param1")String tableNum);
}
