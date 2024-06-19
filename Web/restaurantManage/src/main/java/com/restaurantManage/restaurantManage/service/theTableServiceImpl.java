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
    public List<theTable> getAllTableByCapacity(int capcacity) {
        return thetablerepository.getTableByCapacity(capcacity);
    }

    @Override
    public theTable getTableById(String tableId) {
        return thetablerepository.findById(tableId).orElseThrow(RuntimeException::new);
    }

    @Override
    public theTable updateTable(theTable table) {
        return thetablerepository.save(table);
    }

    @Override
    public void selectTable(int guestNum, String tableId) {
        if(guestNum < 1 || thetablerepository.findById(tableId).isEmpty()){
            throw new IllegalArgumentException("wrong parameters");
        }
        thetablerepository.guestToTable(guestNum,tableId);
    }


}
