// By River@SJ

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ƺ�");
	set("long", @LONG
��ˮ���˹��ˣ���Դ�ھ�Ȫ�����ĺ�ˮ�����³Ǻ��������������ˮ��
ȥ���𽥼�ǿ��Ю����ǧ��ֵĸ�ԭ��ɳ���Ʋ��ɵ��������ϱ�ȥ�����ڴ˴�
ˮ���ļ���������������֬�ᡣ�������µĻƺӴ����㼴���ڴˡ�
LONG );
	set("exits", ([
		"west" : __DIR__"huanghe_2",
		"southeast" : __DIR__"dukou3",
	]));

	set("outdoors", "����");
	setup();
}
