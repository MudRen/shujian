// ROOM:mudao4.c
// Created by Numa 19990912
// Revised by Darken

inherit ROOM;

void create()
{
        set("short","Ĺ��");
        set("long",@LONG
����һ��ͨ��Ĺ�ҵ�ͨ�������Ծ��ǹ����䱦��
ͨ������˷�����չ���ߵͲ�ƽ���㿴��ͷ�����͡�
LONG);
        set("exits",([
                "down" : __DIR__"mushi",
        ]));

        set("no_clean_up",0);
        setup();
}

void init()
{
      string dir;
      mixed *local;
      int h;
      local = localtime(time()*60);
      h = local[2];
      if (h>12)
          h = h - 12;
      switch(h){
            case 1:
                    dir = "northup";break;
            case 2:
                    dir = "north";break;
            case 3:
                    dir = "northdown";break;
            case 4:
                    dir = "northeast";break;
            case 5:
                    dir = "east";break;
            case 6:
                    dir = "southeast";break;
            case 7:
                    dir = "southup";break;
            case 8:
                    dir = "south";break;
            case 9:
                    dir = "southdown";break;
            case 10:
                    dir = "southwest";break;
            case 11:
                    dir = "west";break;
            case 12:
                    dir = "northwest";break;
      }
      delete("exits");
        this_player()->delete_temp("thd/step");
        this_player()->delete_temp("thd/step1");
      set("exits/down", __DIR__"mushi");
      set("exits/"+dir, __DIR__"mudao3");
}

