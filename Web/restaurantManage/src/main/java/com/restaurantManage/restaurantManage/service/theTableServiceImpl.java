package com.restaurantManage.restaurantManage.service;

import com.restaurantManage.restaurantManage.DAO.theTable;
import com.restaurantManage.restaurantManage.DAO.theTableRepository;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class theTableServiceImpl implements theTableService{

    private final theTableRepository thetablerepository;

    public theTableServiceImpl(theTableRepository thetablerepository) {
        this.thetablerepository = thetablerepository;
    }


    @Override
    public List<theTable> getAllTable() {
        return thetablerepository.findAll();
    }

    @Override
    public theTable getTableById(String tableId) {
        return thetablerepository.findById(tableId).orElseThrow(RuntimeException::new);
    }

    @Override
    public void updateTable(theTable table) {
        thetablerepository.save(table);
    }

    @Override
    public void selectTable(int guestNum, String tableId) {
        thetablerepository.guestToTable(guestNum,tableId);
    }


}
