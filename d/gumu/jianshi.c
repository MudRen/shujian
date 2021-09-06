// jianshi.c
// By River 98.10
inherit ROOM;
#include <ansi.h>

void create()
{
      set("short", HIC"����"NOR);
      set("long", @LONG
һ�����������ʯ�ң��ܶ��ֽ�������ضѷ��ڵ��ϡ���Χ�Ļ���յ���
��ʯ�ҵƻ�ͨ����������Ĺ������վ��������ϸ��ѡ�Լ����ֵı��С�ǽ�Ƿ�
��һ��ľ�ƵĻ��߼�(jia)���������Щ��Ĺ����ƽʱ�����õĻ��ߡ�
LONG
      );

      set("exits", ([
	    "south" : __DIR__"gmqs",
      ]));

      set("item_desc", ([
           "jia" :"һ��ľͷ�Ƴɵļ��ӣ������������(armor)�Ȼ��ߡ�\n\n"+
                  "�����ʽ: na armor from jia��\n",
      ]));

      set("objects", ([
              BINGQI_D("changjian") : 1,
              BINGQI_D("gangjian")  : 1,
              BINGQI_D("duanjian")  : 1,
              BINGQI_D("zhujian")   : 1,
              BINGQI_D("mujian")   : 1,
      ]));
      setup();
}

void init()
{
      add_action("do_get",({"get","na"}));
}

int do_get(string arg)
{
      object me,ob;
      string arg1,arg2;
      me=this_player();
      if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
          return notify_fail("�����ʽ: na <��������> from jia��\n");
      if (arg2!="jia")
          return notify_fail("�����ʽ: na <��������> from jia��\n");
      if(me->query_temp("gumu/��"))
          return notify_fail("����ô��ô̰�ģ��ù��˻�Ҫ�ã�\n");
      if(me->query("combat_exp") > 120000)
          return notify_fail("�������ѵ�һ���̶ȣ�������ʳ�����ɡ�\n");
      if (arg1 =="armor"){
          ob=new(ARMOR_D("armor")); 
          ob->move(me);
          message_vision("$N�ӻ��߼����ó�һ��$n��\n",me, ob); 
          me->set_temp("gumu/��",1);
          return 1;
      }     
      return notify_fail("���߼���û������Ҫ�õĶ�����\n");
}

int valid_leave(object ob, string dir)
{
        string* jian = keys(query("objects"));
        object* sword = deep_inventory(ob);
        int i = sizeof(sword), count = 0;
        while (i--)
                if (member_array(base_name(sword[i]), jian) != -1) count++;
        if (count > 1) return notify_fail("��һ��������ô�ལ�����˲�Ҫ������\n");
        return ::valid_leave(ob, dir);
}
