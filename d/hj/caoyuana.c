// caoyuana.c ��ԭ
inherit ROOM;
void create()
{
        set("short", "��ԭ��Ե");
        set("long", @LONG
�����Ǵ��ԭ��ɳĮ����֮�أ������ϡ���ܣ��������������ȥ������
�м�������̤������ӡ�����������ﳣ�����̶����������Ϸ�������Щ���̡�
LONG);
        set("exits", ([
            "east" : "/d/xingxiu/shamo4",
            "westup" : __DIR__"caoyuan2",
            "southwest" :__DIR__"caoyuan1",
            "north" : __DIR__"caoyuan",
            "south" : __DIR__"caoyuan",
        ]));
        set("outdoors", "��ԭ");
        setup();
}

int valid_leave(object me, string dir)
{
       if (dir == "north") me->add_temp("mark/steps",1);
       if (dir == "south") me->add_temp("mark/steps",-1);         
       if (me->query_temp("mark/steps") == 4){
            me->move(__DIR__"hswz");
            me->delete_temp("mark/steps");
             return notify_fail("��������\n");
       }  
       if (me->query_temp("mark/steps") == -4){  
           me->move(__DIR__"caoyuan8");
           me->delete_temp("mark/steps");
             return notify_fail("��������\n");
       }           
       return ::valid_leave(me, dir);
}
