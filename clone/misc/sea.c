#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "��");
	set("outdoors","����");
        set("long", "һ���޼ʵĴ󺣣�����Ϧ������û�벨�ģ��յ�ˮ����������ߣ���˸������һ����ͷ
������ӿ���ȵ��������˽����������������һ�½�ʵ��ˮǽ�����һ�����죬ֻ���
��ľ��ɣ���Щ��ת��ȥ��\n");
        set("no_clean_up", 1);
	setup();
}

void init()
{
   string dest;
   if(this_player()->is_character()) {
        tell_object(this_player(), HIR"\nһ�����˴����������������졣������\n"NOR);
        this_player()->unconcious();
        dest = ({ "/d/mingjiao/xikou", "/d/mingjiao/lsd/anbian"})[random(2)];
        this_player()->move(dest);
        message("vision", "ͻȻһ����ι�����һ��"+this_player()->name()+"�Ӻ��ﴵ�ϰ�����\n",environment(this_player()), ({this_player()}));
        }   
}

int clean_up() { return 0; }
