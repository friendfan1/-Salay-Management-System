package com.restaurantManage.restaurantManage.service;

import com.restaurantManage.restaurantManage.DAO.theTable;
import org.springframework.data.repository.query.Param;

import java.util.List;

public interface theTableService {
    List<theTable> getAllTable();

    List<theTable> getAllTableByCapacity(int capacity);

    theTable getTableById(String tableId);

    theTable updateTable(theTable table);

    void selectTable(int guestNum, String tableId);
}
