// /d/xingxiu/silk5.c
inherit ROOM;

void create()
{
        set("short", "��¡ɽ");
        set("long", @LONG
��ɽ��������ɽ���ϣ���Ȼ���ܲ�������ɼ���ɡ��롢���������ľ��
��ľ�ԡ����͵��䣬�ļ����ࡣ����̫�ס���ҺȪ�����СϪɽ����������
�������д�Ͽ�ӣ��峺���ף��ϱ���ԽϿ�ȡ�������ʪ�����½ϵͣ�Ϊ����
����ʤ�ء�
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "north" : __DIR__"silk5",
        ]));

        set("objects", ([
                __DIR__"npc/yang" : 2,
        ]));

        set("coor/x",-270);
  set("coor/y",80);
   set("coor/z",0);
   set("coor/x",-270);
 set("coor/y",80);
   set("coor/z",0);
   setup();
}