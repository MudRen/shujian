inherit ROOM;

void create()
{
        set("short", "���ʴ�ʿԺ");
        set("long",@LONG
���ʴ�ʿԺ������ǰ˲���������ٰ��ޡ���ǧ���䡣��������
�������������������������̴�㡣����֪��ɮ��æ�ò����ֺ�����
�����������޹������������󣬱�����ɽ��
LONG);
        set("exits", ([              
              "southdown" : __DIR__"3wg",
              "west" : __DIR__"qxg",
              "north" : __DIR__"road5",
	]));	
        set("coor/x",-390);
  set("coor/y",-310);
   set("coor/z",30);
   setup();
}
