// huazanganzd.c
// ����������

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long",@long
�����Ƕ���ɽ�𶥻����ֵ���������ֹ�ģ��󣬵�����ש�̵أ��м�
�������������������������ǰ����һ��ľ���������������Թ�ߵ�ݡ�
�Դ����Ҹ���һ����ǽӴ���͵ĵط���������ͨ��һ����㳡��ֻ�ж�
�ҵ��Ӳ��ܹ�ȥ��
long);

	set("exits",([
	    "east" : __DIR__"dcedian",
	    "west" : __DIR__"xcedian",
	    "south" : __DIR__"huazangangc",
	    "out" : __DIR__"huazangan",
]));
        set("objects",([
		CLASS_D("emei") + "/jing-xin" : 1,	      
          ]));
	setup();	
}
