//tjing.c
//Csl 2000.04.26

inherit ROOM;
void create()
{
        set("short", "�쾮");
        set("long",@LONG
��һ�߽��쾮����ῴ����ɫ��ש�̳ɵ�·�棬·��Χ�����ļ����ݣ���
���м��������Ժ�䣬���Ǹ�СС���쾮�����õ�Ҳ�Ǿ���ϸ�£���߽��ġ�
LONG
        );
	set("outdoors", "����");
        set("exits",([
		"south"  :  __DIR__"qiant",
		"north"  :  __DIR__"zhengt",
		"west"   :  __DIR__"chelang1",
	]));
	setup();
}
