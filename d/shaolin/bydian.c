// Room: /d/shaolin/bydian.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "���µ�");
	set("long", @LONG
���ǰ��µ������¹�����ʿ����ʿ�߾��������ϣ����о�ƿ��ü��
΢�����ǳЦ���·���˼伲��ȴ����ģ��־��ͻ������з��˺�ľ����
�����㰸�Ϲ�Ʒ�뱸�����ʮ����ʢ��
LONG
	);

	set("exits", ([
		"west" : __DIR__"kchang",
	]));

       
	set("coor/x",60);
  set("coor/y",420);
   set("coor/z",130);
   setup();
}



