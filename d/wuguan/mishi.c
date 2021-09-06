// mishi.c

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",BLU"����"NOR);
        set("long",@long
����ǰͻȻ���ָ��������ң��������С�����ڷ���һЩʯ��ʯ�Σ�ʯ��
ʯ�������϶ѷ���һЩʯ�Ƶ����󣬶������˻ң������ƺ��Ѿ��ܾ�û������
�ˡ��������һ��ǽ��(wall)�Ϻ������Щʲô��
long);

        set("item_desc", ([
            "wall" : "һ����ǽ�϶����������˲�����ֵķ��ţ�fuhao����\n",
            "fuhao" : "����ֵֹķ��ţ�������ԣ�lingwu����\n",
        ]));
 
	set("exits" ,([
            "out" : __DIR__"jiashan1",
	]));

        setup();
}

void init()
{  
        add_action("do_study", "study");
        add_action("do_study", "lingwu");
}

int do_study(string arg)
{
        object me;

        me = this_player();
        if ( !arg || arg != "fuhao" )
                 return notify_fail ("�����ж�ʲô��\n");
        if (me->is_busy() || me->is_fighting()){
           write("����æ���ģ�\n");
           return 1;
           }
        if ((int)me->query_skill("literate", 1) < 1) {
            write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
            return 1;
            }
        if(me->query("potential", 1) < 1 ) {
            write ("���Ǳ��û�ˣ������ٽ�һ�������ˡ�\n");
            return 1;
            }
        if ((int)me->query("jing") < 20) {
            me->receive_damage("jing", 10);
            write("��̫���ˣ��Ѿ�û���������ж�ǽ���ϡ�������š����ˣ�\n");
            return 1;
            }
            me->receive_damage("jing", 10 + random(5));
            tell_room(this_object(), me->name() + "��ר���о�ǽ���ϵġ�������š���\n", ({ me }));         
        if ( (int)me->query_skill("shenzhao-jing", 1) < 15 && (int)me->query_skill("force",1) > 5 ) {
            me->improve_skill("shenzhao-jing", me->query("int")/3+1);
            me->add("potential",-1);	     
            write("�����ǽ���ϵġ�������š���ĥ��һ������ƺ��ԡ����վ��������ĵá�\n");
            return 1;
            } 
        if ((int)me->query_skill("force", 1) <= 5) {
            write("��Ļ����ڹ�̫�ͣ����˰�����ǲ��������ŵĺ��塣\n");
            return 1;
	    }
        write("���Ѿ��ѷ����о�͸������Ҳ���ܴ�����ѧ��ʲô�����ˡ�\n");
        return 1;
}
 
