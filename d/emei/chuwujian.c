// chuwujian.c
// �����
inherit ROOM;
#include <room.h>
void create()
{
	set("short","�����");
	set("long",@long
������Ƕ��һ����ֵĴ���䣬���ܶ��Ǽ��ӡ�һ�����Ϸ����˸�����
�����г��������������޵ȣ�������Ŀ����һ�����Ϸ��˸��ַ��ߡ�����һ
�����ϰ������С���ӣ�ԭ����װ��ҩƷ��ҩ��һλʦ̫������������
��Ʒ����æµ��������ߡ���������и�С¥�ݡ��������ի���ˡ�
long);
	set("exits",([
	    "north" : __DIR__"huazanganzt",
	    "up" : __DIR__"huazangancj",
]));
        set("objects",([
		CLASS_D("emei") + "/jing-feng" : 1,	    
          ]));
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "up" && me->query("family/family_name") != "������" && objectp(present("jingfeng shitai", environment(me))))
		return notify_fail("����ʦ̫�ȵ������ؾ�¥�����ɵ��Ӳ������ڡ���\n");
	return ::valid_leave(me, dir);
} 
