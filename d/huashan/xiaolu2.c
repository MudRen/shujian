// Room: /d/huashan/xiaolu2.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "Сɽ·");
        set("long", @LONG
�����ǻ�ɽ��һ��Сɽ·�����ƽ�Ϊƽ�������������ط���ô�վ�������
��������ܾ����ĵģ�������߽���һ��������Դ��
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                "southeast" : __DIR__"xiaolu1",
                "westup" : __DIR__"siguoya",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "��ɽ" );

        set("coor/x",50);
  set("coor/y",50);
   set("coor/z",60);
   setup();
}

void init()
{
        object me = this_player();
        if( me->query("family")
         && me->query("family/family_name") != "��ɽ��"
         && me->query("fengset")){
          me->delete("fengset");
        }
}
