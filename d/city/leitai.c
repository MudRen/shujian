// leitai.c ������̨ǰ�㳡
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","��̨ǰ�㳡");
        set("long",@long
������������̨ǰ���һ�����͹㳡���������������̨�ϱ��䣬����
����ɽ�˺��������Ҳ���������֣���ô��������̨���Ա��԰ɡ�
long);
        set("exits",([
              "tiandi" : "/d/wizard/lt",
              "fengyun" : "/d/wizard/lt1",
              "longhu" : "/d/wizard/lt2",
              "southeast" : __DIR__"guangchangbei",
//                "west" : "/cmds/leitai/bwdh/view1",
//                "east" : "/cmds/leitai/bwdh/view4",
        ]));
        set("outdoors", "����");
        set("coor/x",100);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",100);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",100);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",100);
  set("coor/y",10);
   set("coor/z",0);
   setup();
}                                         

int valid_leave(object me,string dir)
{
        object *ob;
        int i;       
        
        if(me->query_condition("killer") > 0 && dir != "southeast")
        	return notify_fail(HIW"\nͨ�������ý�����̨�صأ�\n\n"NOR);
        ob = deep_inventory(me);
        i = sizeof(ob);
        while (i--)
        if ((ob[i]->is_character() || ob[i]->query("unique")) && dir != "southeast")
          	return notify_fail(HIW"\n�㲻�ô��˻�����������̨�صء�\n\n"NOR);
        return ::valid_leave(me, dir);
}
