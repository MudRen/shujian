// che1.c 

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIY"������"NOR);
        set("long", @LONG
�ɾ�����ĳ�����������λ�����ź�ɫ�Ľ��С���ǰ�ϳ�����������
�ظ����������е����������ڳ��ڣ�ȴ�����о��𵴡�͸���ĳ������ܹ���
�ʹ��������ľ�ɫ��
LONG
        );
        set("no_fight",1);

        setup();
}

void run(object ob)
{
        if (environment(ob) == this_object())
        ob->move(__DIR__"che2", 1);        
}

void init()
{
       object ob = this_player();
       call_out("run", 15, ob);
}
