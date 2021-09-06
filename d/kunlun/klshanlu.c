// klshanlu.c (kunlun)

#include <ansi.h>
#include <room.h>
#include <wanted.h>

inherit ROOM;

void create()
{
	  set("short", "����ɽ´");
	  set("long",@long
��������ɽ��ѩɽ���࣬���Ӵ�����Զ�����أ���������Ʋʼ����ɫ��
����ÿ�괺���Ժ󣬱�ѩ�ڻ������һ�ɹ��峺Ϫ�������볤�����ƺӡ�
long);
	  set("exits",([
              "northup" : __DIR__"shanmen",
	      "east" : __DIR__"shankou",
	      "west" : "/d/fairyland/shanlu1",
          ]));
          set("outdoors", "����");
          setup();
}

int valid_leave(object me, string dir)
{
       if (dir == "northup" && is_wanted(me)) return 0;
        return ::valid_leave(me, dir);
}
