package com.restaurantManage.restaurantManage.Controller;

import com.restaurantManage.restaurantManage.DAO.theTable;
import com.restaurantManage.restaurantManage.Response;
import com.restaurantManage.restaurantManage.service.GuestService;
import com.restaurantManage.restaurantManage.service.theTableService;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.util.List;

import static com.restaurantManage.restaurantManage.Response.newFail;
import static com.restaurantManage.restaurantManage.Response.newSuccess;

@Controller
public class TableController {
    private final theTableService theTableService;
    private final GuestService guestService;

    public TableController(theTableService theTableService, GuestService guestService) {
        this.theTableService = theTableService;
        this.guestService = guestService;
    }

    @GetMapping("/{id}/tables")
    public String tables(Model model1, @PathVariable int id, HttpServletResponse response) {
        // 获取所有桌子信息
        List<theTable> tables = theTableService.getAllTable();

        // 将顾客编号和桌子信息传递到HTML页面
        model1.addAttribute("customerNumber", id);
        model1.addAttribute("tables", tables);

        // 设置Cookie
        Cookie cookie = new Cookie("customerNumber", String.valueOf(id));
        cookie.setMaxAge(3 * 60 * 60); // 设置Cookie的有效期为3小时
        cookie.setPath("/");
        response.addCookie(cookie);

        return "tables";
    }

    @GetMapping("/selectTable/{id}&{tableId}")
    public String selectTable(@PathVariable int id, @PathVariable String tableId, HttpServletResponse response) {
        // 在此处添加逻辑以处理选择桌子的操作，例如更新桌子的状态
        theTableService.selectTable(id, tableId);

        // 设置表示已经选择桌子的Cookie
        Cookie selectedTableCookie = new Cookie("selectedTable", tableId);
        selectedTableCookie.setMaxAge(12 * 60 * 60); // 设置Cookie的有效期为3小时
        selectedTableCookie.setPath("/");
        response.addCookie(selectedTableCookie);

        // 重定向到菜单页面
        return "redirect:/" + tableId + "/menu";
    }

    @PostMapping("/")
    @ResponseBody
    public ResponseEntity<?> submitQueueForm(@RequestBody theTable theTable, HttpServletResponse response) {
        int id = guestService.guestCome(theTable.getCapacity(), theTable.getCapacity());
        boolean success = (id > 0);
        if (success) {
            // 设置Cookie
            System.out.print("访问queue成功");
            Cookie cookie = new Cookie("customerNumber", String.valueOf(id));
            cookie.setMaxAge(12 * 60 * 60); // 设置Cookie的有效期为12小时
            cookie.setPath("/");
            response.addCookie(cookie);
            System.out.print(guestService.getPeopleQuantityBefore(id));
            if(guestService.getPeopleQuantityBefore(id) == 0){
                return ResponseEntity.ok(newSuccess("/" + id + "/tables"));
            }
            else if(guestService.getPeopleQuantityBefore(id) < 0){
                String tableID = guestService.getTableIdByGuestID(id);
                return ResponseEntity.ok(newSuccess("/" + tableID + "/tables"));
            }
            return ResponseEntity.ok(newSuccess("/" + id + "/queueing"));
        } else {
            return ResponseEntity.status(HttpStatus.BAD_REQUEST)
                    .body(newFail("Bad Request").toString());
        }
    }

    @GetMapping ("/{id}/queueing")
    public String getQueueingPage(@PathVariable int id, Model model){
        int peopleQuantity = guestService.getPeopleQuantityBefore(id);
        System.out.print(peopleQuantity);
        if(peopleQuantity == 0){
            return "redirect:/" + id + "/tables";
        }
        else if(peopleQuantity < 0){
            String tableID = guestService.getTableIdByGuestID(id);
            return "redirect:/" + tableID + "/menu";
        }
        else{
            model.addAttribute("id",id);
            model.addAttribute("peopleQuantity",peopleQuantity);
            return "queueing";
        }

    }

    @GetMapping("/")
    public String queue(HttpServletRequest request, HttpServletResponse response,Model model) {
        // 检查是否存在customerNumber的Cookie
        Cookie[] cookies = request.getCookies();
        if (cookies != null) {
            String customerNumber = null;
            String selectedTable = null;
            for (Cookie cookie : cookies) {
                if ("customerNumber".equals(cookie.getName())) {
                    customerNumber = cookie.getValue();
                } else if ("selectedTable".equals(cookie.getName())) {
                    selectedTable = cookie.getValue();
                }
            }
            if (customerNumber != null) {
                if (selectedTable != null) {
                    // 重定向到选菜页面
                    return "redirect:/" + selectedTable + "/menu";
                } else {
                    // 重定向到选座页面
                    int id = Integer.parseInt(customerNumber);
                    System.out.print(id);
                    int num = guestService.getPeopleQuantityBefore(id);
                    if(num == 0){
                        return "redirect:/" + customerNumber + "/tables";
                    }
                    else if(num == -1){
                        String tableId = guestService.getTableIdByGuestID(id);
                        return "redirect:/" + tableId + "/menu";
                    }
                    else {
                        model.addAttribute("id",id);
                        model.addAttribute("peopleQuantity",num);
                        return "queueing";
                    }
                }
            }
        }
        // 如果没有找到相应的Cookie，则返回排队页面
        return "queue";
    }

    @GetMapping("/retrieve-cookie")
    @ResponseBody
    public String retrieveCookie(HttpServletRequest request) {
        Cookie[] cookies = request.getCookies();
        if (cookies != null) {
            for (Cookie cookie : cookies) {
                if ("customerNumber".equals(cookie.getName())) {
                    return "Welcome back, customer number: " + cookie.getValue();
                }
            }
        }
        return "No customer cookie found";
    }
}
