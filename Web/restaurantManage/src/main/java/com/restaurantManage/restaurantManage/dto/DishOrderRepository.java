package com.restaurantManage.restaurantManage.dto;

import jakarta.persistence.EntityManager;
import jakarta.persistence.PersistenceContext;
import jakarta.persistence.StoredProcedureQuery;
import jakarta.transaction.Transactional;
import org.springframework.stereotype.Repository;

import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;

@Repository
public class DishOrderRepository {
    @PersistenceContext
    private EntityManager entityManager;

    @Transactional
    public List<DishOrderDTO> findAllOrderByTableNum(String TableNum){
        //System.out.print("111111111111111111");
        StoredProcedureQuery query = entityManager.createNamedStoredProcedureQuery("findAllOrderByTableNum");
        query.setParameter("TableNum",TableNum);
        query.execute();

        // 获取存储过程返回的结果集
        List<DishOrderDTO> resultList = query.getResultList();
        System.out.print("111111111111111111");

        // 处理查询结果映射到DTO对象中
        /*List<DishOrderDTO> mappedResult = new ArrayList<>();
        for (Object[] row : resultList) {
            String dishName = (String) row[0];
            Float price = (Float) row[1];
            Float discount = (Float) row[2];
            LocalTime time = (LocalTime) row[3];
            String state = (String) row[4];

            DishOrderDTO dto = new DishOrderDTO(dishName, price, discount, time, state);
            mappedResult.add(dto);
        }*/
        return resultList;
    }
}