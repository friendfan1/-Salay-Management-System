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
        StoredProcedureQuery query = entityManager.createNamedStoredProcedureQuery("findAllOrderByTableNum");
        query.setParameter("TableNum",TableNum);
        query.execute();

        // 获取存储过程返回的结果集
        List<DishOrderDTO> resultList = query.getResultList();

        return resultList;
    }
}