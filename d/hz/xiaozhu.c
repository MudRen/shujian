// /u/beyond/hz/xiaozhu.c С��
 
inherit ROOM;
void create()
{
        set("short","С��");
        set("long", @LONG
�����и�ʽ������԰��С�������ֽ������ŵ��Ƶ͸߶��������ơ�����
����������������ͥԺ����ɽ��ˮ�Ĵ���ͤ����ѩͤ�������ƣ�ͤ������Ů
�ֹ����������ﶯ���Ĺ�������Ϊ��Ʒ�����۾����ˡ�
LONG
        );
        set("exits", ([
            "southwest" : __DIR__"changlang1",
            "east" : __DIR__"shuichi",
]));
        set("coor/x",60);
  set("coor/y",-300);
   set("coor/z",0);
   setup();
}
