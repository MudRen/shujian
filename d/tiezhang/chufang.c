// chufang.c ����

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������ư�ĳ�����������һ����¯�����ռȥ��һ��ķ��䡣����
���кܶ���ۣ���ͬʱ���ܶ��ֲˡ���λ���и�нƸ���ĳ�����������æµ�š�
�������������Ÿ��ַ��˵���ζ���������˴������Ρ�
LONG
        );

        set("exits", ([ 
"south" : __DIR__"zoulang-3",
]));

        set("objects", ([ 
__DIR__"npc/TZ_chuzi" : 1,
])); 

        set("no_clean_up", 0);
        set("no_fight", 1);

        set("coor/x",-350);
  set("coor/y",-240);
   set("coor/z",10);
   setup();
}

int valid_leave(object me, string dir)
{
        object *ob = deep_inventory(me);
        int i = sizeof(ob);
        if((dir == "south")){
          while (i--)
          if(ob[i]->id("mi fan") || ob[i]->id("hongshao niurou") || ob[i]->id("ruzhu"))
             return notify_fail("������æ�ܳ�����ס�㣺�Ա��˻�Ҫ������������������ǰɣ�\n");      
        }
        return ::valid_leave(me, dir);
}
