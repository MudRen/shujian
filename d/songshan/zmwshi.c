// Room: /u/swl/songshan/zmwshi.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
һ�����ң�һ�����µ�ζ���˱Ƕ���������ǽ�Ϲ��Ÿ��ֱ�������
�����Լ�����ϰ������顣��������������װ�ο�����ȷ��ʧһ����ʦ
�����ɡ�
LONG);
	set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"qindian",
        ]));
    set("indoors", "��ɽ");
	set("coor/x",70);
  set("coor/y",340);
   set("coor/z",120);
   setup();
}
