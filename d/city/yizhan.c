// Room: /d/city/yizhan.c

inherit ROOM;

void create()
{
        set("short", "��վ");
        set("long", @LONG
����������վ�������ͺ;�������������ġ�ÿ�������ƥ���������
�����������Ρ������������Ҫ�ĵ����ֻҪ�ŵ����һ��֮�ھ��Կ���
�͵���������һ���¿��Ļ��꣬��˵������ϰ�ǳ�Ư����
LONG
        );
        set("exits", ([
                "west" : __DIR__"beidajie3",
                "north" : __DIR__"huadian",
        ]));

/*
        set("objects", ([
                __DIR__"npc/youtanzhi" : 1,
        ]));

*/
        set("coor/x",130);
  set("coor/y",0);
   set("coor/z",0);
   set("coor/x",130);
  set("coor/y",0);
   set("coor/z",0);
   set("coor/x",130);
  set("coor/y",0);
   set("coor/z",0);
   setup();
}

int valid_leave(object me, string dir)
{
        object mbox;

        if (in_input(me)) return 0;
        if( mbox = me->query_temp("mbox_ob") ) {
          tell_object(me, "�㽫���仹������̹֮��\n");
                destruct(mbox);
        }
           return ::valid_leave(me, dir);
}

