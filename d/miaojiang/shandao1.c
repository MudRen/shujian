// /u/dubei/miaojiang
 

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
������ͨ���置��ɽ�����置�ش��ȴ������������ţ�һ�����ͷ�󺹡�
LONG
        );

        set("exits", ([
         "west" : __DIR__"shandao2",
                "southwest" : __DIR__"myp",
        ]));
     
      
        set("outdoors", "miaojiang");

        setup();

}
