// �ɿ����
// caikuang-chang0.c
// augx@sj 9/10/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","�ɿ����");
	set("long",
"������һ���޴�Ŀ�ɽ��ɽ�ţ��˵�ʢ�����ֿ�ʯ������ʯ�Ǵ��������
��ȱ��ԭ�ϣ����Դ˵ؾ����вɿ��˳�û���������֡�����ɽ·Ҳʮ�ֶ���
��ɽ��������ɻ������Գ����вɿ����ߴ������ɽ�¶��������ڹ�
���Ѿ���ɽ·�ĸ�����Ҫ֮��������ָʾ����ָ������ͬʱ����Ѳ��Ѳ��ɽ
·����ֹ��ɱ�¼���
"); 

	set("objects",([
		__DIR__"npc/xunbu" : 2,
	]));
        
	set("exits",([
		"northeast" : "/d/huanghe/shulin2",
             "westup" : __DIR__"caikuang-chang10",
	]));
	
	set("outdoors", "���ݽ���");
	set("incity",1);
	setup();
}

int clean_up()
{
	return 1;
}
