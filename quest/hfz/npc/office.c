//edit by rock
//2008.10.16

#include <ansi.h>
inherit NPC;

#define MIRROR_SYS "/quest/hfz/sys/mirror_sys"

int ask_job();

void create()
{

        set_name("�۲�9ë", ({ "master nine", "master","nine" }));
        set("title", "������");

        set("gender", "����");
        set("age", 35);
        set("long","����һ������������������������޳ܵļһ\n");

	set("inquiry", ([ 
        	"�˷�" : (: ask_job :),
            ])); 

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}

int ask_job()
{
	object me;
	object *team,memory;
int i;
	int td;
td = time() / 86400;	
	me = this_player();
	if(!me->is_team_leader())
	{
		tell_object(me,"�㲻����ӡ�\n");
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

	if(MIRROR_SYS->query_room_amount() >= 20)
	{
		tell_object(me,"�����Ѿ�����̫�࣬��ӭ�´β��롣\n");
		return 1;
	}

if (team[i]->query("hfz_ask/which_day2") != td)
{
                team[i]->delete("hfz_ask/times");

}
if (team[i]->query("hfz_ask/which_day2") == td &&
            team[i]->query("hfz_ask/times") >= 3) 
{
tell_object(me,"" + team[i]->query("name") + "�����Ѿ��ﵽ���븱�����������ˡ�\n");

                return 1;
}
             
team[i]->set("hfz_ask/which_day2", td);
              team[i]->add("hfz_ask/times", 1);



}


	//ɾ���ɵĸ���
	memory = me->query_temp("mirror/mirror_memory");
	if(objectp(memory))
	{
		memory->delete("user_id");
	}
	//�����µĸ���
	MIRROR_SYS->mirror(team,me);
	return 1;
        team->move("quest/hfz/damen");
}