// by XiaoYao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ƺ��뺣��");
	set("long", @LONG
�ƺ�������ظ�ԭ��������ԭ������ƽԭ���ܳ�һ����Ű���������
��󺣡��ƺ����ʵ�����Ӵ���������ɫ�ĺ�ˮ�ھ���������ȥ��ʹ����
��������ˮʱ�Ŀ�����
LONG );
	set("exits", ([
		"southwest" : __DIR__"huanghe7",
		"north" : __DIR__"road2",
	]));

	set("outdoors", "�ƺ�");
	setup();
}
