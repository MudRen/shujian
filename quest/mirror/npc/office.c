//edit by rock
//2008.10.16

#include <ansi.h>
inherit NPC;

#define MIRROR_SYS "/quest/mirror/sys/mirror_sys"


int ask_job();

void create()
{

        set_name(HIG"Ԭ���"NOR, ({ "yuan chonghuan", "yuan" }));
set("title",HIR"���ɶ�ʦ"NOR);

        set("gender", "����");
        set("age", 40);
        set("long","Ԭ�������Ԫ�أ���һλ�ǹ�����Ŀ��彫��������ɽ������Զ��һ�����������\n");

	set("inquiry", ([ 
        	"����" : (: ask_job :),
            ])); 

        setup();
}


int ask_job()
{
	object me;
	object *team,memory;
	int i;
	me = this_player();

	if(!me->is_team_leader())
	{
		tell_object(me,"�㲻����ӡ�\n");
		return 1;
	}

       if  (me->query("fuben/kangqing/time") && time()-me->query("fuben/kangqing/time") < 21600 )
{
    tell_object(me,"��������ÿ������21600�롣\n");
		return 1;
	}
   
	team = me->query_team();
	if(!pointerp(team) || sizeof(team) < 2)
	{
		tell_object(me,"������ֲ�����\n");
		return 1;
	}
   
for (i = 0;i < sizeof(team);i ++)
{   
if (!team[i])
command("say ��Ķ�����������⣬���ɢ�������齨��\n");

                                       if (!present(team[i]))
                        command("say ��ô�����˲�ȫ����" + team[i]->query("name") + "��ôû����\n");



 if(team[i]->query("fuben/kangqing/time") && 
time()-team[i]->query("fuben/kangqing/time") <21600 )
   {
		tell_object(me,"�������������δ�ﵽ��ȴʱ�䣬�����Ҹ�����\n");
		return 1;
	}
/*
if (!interactive(team[i]) || query_ip_number(team[i]) == query_ip_number(me)) {
command("say ͬIP�Ĳ��ܽ��븱�����������Ѱɡ�");
			return 1;
		}

*/

}

	if(MIRROR_SYS->query_room_amount() >= 20)
	{
		tell_object(me,"�����Ѿ�����̫�࣬��ӭ�´β��롣\n");
		return 1;
	}
	//ɾ���ɵĸ���
	memory = me->query_temp("mirror/mirror_memory");
	if(objectp(memory))
	{
		memory->delete("user_id");
	}
	//�����µĸ���
	MIRROR_SYS->mirror(team,me);
team->set("fuben/kangqing/time",time());
       	return 1;
       
team->move("quest/mirror/guangchang");


}
