/*
package com.restaurantManage.restaurantManage.Controller;

import com.restaurantManage.restaurantManage.DAO.theTable;
import com.restaurantManage.restaurantManage.service.GuestServiceImpl;
import com.restaurantManage.restaurantManage.service.theTableServiceImpl;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;
import org.mockito.junit.jupiter.MockitoExtension;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.ui.ExtendedModelMap;
import org.springframework.ui.Model;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.mockito.Mockito.doNothing;
import static org.mockito.Mockito.when;

@ExtendWith(MockitoExtension.class)
public class TestTableController {

    @Mock
    private theTableServiceImpl theTableService;

    @Mock
    private GuestServiceImpl guestService;

    @InjectMocks
    private TableController tableController;

    @BeforeEach
    public void setUp() {
        MockitoAnnotations.openMocks(this);
    }

    @Test
    public void testTablesValidId() {
        Model model = new ExtendedModelMap();
        List<theTable> tables = new ArrayList<>();
        tables.add(new theTable());

        when(theTableService.getAllTable()).thenReturn(tables);

        String view = tableController.tables(model, 1);
        assertEquals("tables", view);
        assertNotNull(model.getAttribute("customerNumber"));
        assertNotNull(model.getAttribute("tables"));
    }

    @Test
    public void testTablesInvalidId() {
        Model model = new ExtendedModelMap();
        List<theTable> tables = new ArrayList<>();
        tables.add(new theTable());

        when(theTableService.getAllTable()).thenReturn(tables);

        String view = tableController.tables(model, -1);
        assertEquals("tables", view);
        assertNotNull(model.getAttribute("customerNumber"));
        assertNotNull(model.getAttribute("tables"));
    }

    @Test
    public void testSelectTableValidInput() {
        doNothing().when(theTableService).selectTable(1, "T1");

        String view = tableController.selectTable(1, "T1");
        assertEquals("redirect:/T1/menu", view);
    }

    @Test
    public void testSelectTableInvalidId() {
        doNothing().when(theTableService).selectTable(-1, "T1");

        String view = tableController.selectTable(-1, "T1");
        assertEquals("redirect:/T1/menu", view);
    }

    @Test
    public void testSelectTableInvalidTableId() {
        doNothing().when(theTableService).selectTable(1, "");

        String view = tableController.selectTable(1, "");
        assertEquals("redirect:/menu", view);
    }

    @Test
    public void testSubmitQueueFormValidCapacity() {
        theTable table = new theTable();
        table.setCapacity(4);

        when(guestService.guestCome(4, 4)).thenReturn(1);

        ResponseEntity<?> response = tableController.submitQueueForm(table);
        assertEquals(HttpStatus.OK, response.getStatusCode());
    }

    @Test
    public void testSubmitQueueFormInvalidCapacity() {
        theTable table = new theTable();
        table.setCapacity(-1);

        when(guestService.guestCome(-1, -1)).thenReturn(-1);

        ResponseEntity<?> response = tableController.submitQueueForm(table);
        assertEquals(HttpStatus.BAD_REQUEST, response.getStatusCode());
    }

    @Test
    public void testQueuePage() {
        String view = tableController.queue();
        assertEquals("queue", view);
    }
}
*/
