//Xiaoyao 3/24/99
// Modified by snowman 21/05/2000

#include <room.h>
inherit ROOM;

string look_sign();
void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǽ�����ԼĪ���ɼ�����һ���ʯ�ң�ǽ�ںͶ��嶼�Ǵ�ʯ������ǽ
�������һֻ��Ͱ�������ŵ��ľ��ǳ�����ù��������ʹ����ס�˱��ӡ�����
��ǽ�Ͽ���һ��С��(window)��
LONG);

        set("cost", 0);
        set("no_fight", 1);
	set("item_desc",([
        	"window" : (: look_sign :),
        ]));
        setup();
}


string look_sign()
{
        object env, me = this_player();

	if ( me->is_busy() )
		return "����æ���أ�\n";
		
        if(!( env = find_object("/d/city/bingying")) )
        env = load_object("/d/city/bingying");

        tell_room(env, "�㷢����һ˫�۾��ڴ��ӱ���������\n");
        me->add_busy(3);
        return "/cmds/std/look"->look_room(me, env);
}
