inherit ROOM;

#include <ansi.h>
#include <room.h>



void create()
{
        set("short", "�о�����");
        set("long", @LONG
  ��˵����ɹŴ����Ϊ�ù��������£�׼���������Ͻ�ȡ�����Ա��ػء�
��������ɹ�׼���������������ʱָ�Ӿ��ʣ�ʱʱ��ʿ������Ѳ�ߡ�
LONG
        );
        set("xyjob", 1);
        set("outdoors", "����");
        set("objects", ([
                __DIR__"npc/ci-en" : 1,
               __DIR__"npc/jinlun-fawang" : 1,
        ]));

      	setup();
}


