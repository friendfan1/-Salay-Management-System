package com.restaurantManage.restaurantManage.service;

import com.restaurantManage.restaurantManage.DAO.theTable;
import org.springframework.data.repository.query.Param;

import java.util.List;

public interface theTableService {
    List<theTable> getAllTable();

    theTable getTableById(String tableId);

    void updateTable(theTable table);

    void selectTable(int guestNum, String tableId);
}
