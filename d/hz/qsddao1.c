// /u/beyond/hz/qsddao1.c ��ʯ���
 
inherit ROOM;
void create()
{
        set("short","��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ���·���ο�����������ȫ���������������ĺ�
��ɽɫ�ġ�����ı�����һ������ɽ����������Կ���������ͤͤ�������
����Ӱ��
LONG
        );
    set("outdoors", "����");
        set("exits", ([
            "northup" : __DIR__"baoshuta",
            "south" : __DIR__"baidi",
]));
        set("coor/x",60);
  set("coor/y",-320);
   set("coor/z",-10);
   setup();
}
