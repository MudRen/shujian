// /u/dubei/miaojiang
 

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
����ȫ��һƬ���֣���ľ���ʣ��ּ䴫���������������������Ѿ�û��·�ˡ�
LONG
        );

        set("exits", ([
               
                "southeast" : __DIR__"xiaolu1",
           
        ]));
 

        set("no_clean_up", 0);
        set("outdoors", "miaojiang");

        setup();

}
