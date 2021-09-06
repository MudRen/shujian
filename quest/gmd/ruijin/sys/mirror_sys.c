//edit by rock
//2008.10.16
//���ļ����ᱻ��¡

#include <ansi.h>
#include <localtime.h>
#include "/quest/gmd/ruijin/sys/list.h"

#define MAX_ROOM_INDEX 20
#define OFFICE_NPC     "/quest/gmd/npc/office"
#define MIRROR_MEMORY  "/quest/gmd/ruijin/sys/memory"
#define KILLER_NPC     "/quest/gmd/ruijin/npc/killer"
#define BOSS_NPC       "/quest/gmd/ruijin/npc/zhuang"
#define MAX_KILLER_INDEX 10

//ȫ�ֱ���
int make_room_index;
int ob_time;

//��������

int mirror(object* player,object leader);
void del_npc();
void mirror_ok(object me);
varargs void make_killer(object *player,int boss);

//��������ѯ��������������
int query_room_amount() { return make_room_index; }

//��ʼ��




//NPC���ã����쾵������
int mirror(object* player,object leader)
{
	object maps,memory,start_room;
	int i,size,j,index;
	mixed time;
	string fileName;

	if(!player || make_room_index >= MAX_ROOM_INDEX || !leader ) return 0;

	//�����ڴ�
	if(!memory = new(MIRROR_MEMORY)) return 0;

	memory->set("leader",leader);
	//�ж���������Ƿ����Ҫ��
	size = sizeof(player);
	for(i=0;i<size;i++)
	{
		if(!player[i] || !userp(player[i]) || !living(player[i]) || !pointerp(player[i]->query_team()))
		{
			destruct(memory);
			return 0;//continue;
		}

		//�ҳ��ӳ�
		if(player[i]->is_team_leader())
		{
			leader = player[i];
			
		}
		memory->set(sprintf("user_id/%d",i),player[i]->query("id"));
		memory->set(sprintf("user/%d",i),player[i]);
		player[i]->set_temp("mirror/mirror_memory",memory);

		tell_object(player[i],HIY"��Χ��������������Ϊ�����쾵�����Ժ�......\n"NOR);
		player[i]->disable_player("<���뾵����>");
		player[i]->set_temp("block_msg/all",1);
	}

	//��������
	size = sizeof(mirror_maps);
	for(j=0;j<size;j++)
	{
		maps = new(mirror_maps[j]);
		if(maps)
		{
			//���е�ͼ��memory
			memory->set(sprintf("maps/%d",j),maps);
sscanf(mirror_maps[j],"/quest/gmd/ruijin/%s",fileName);
			memory->set(fileName,maps);
			maps->set("memory",memory);
                 if(maps->query("short") == HIY"�����"NOR);
			{
				start_room = maps;
			}
			index ++;
		}
			}
	if(index < 1 || !start_room  )
	{
		size = sizeof(player);
		for(i=0;i<size;i++)
		{
			player[i]->enable_player();
			player[i]->delete_temp("block_msg");
			tell_object(player[i],"Error: ��������ʧ�ܣ�����ϵ��ʦ��\n");
		}

		memory->delete_map();
		destruct(memory);
		time = localtime(time());
		log_file("mirror",sprintf("%d��%d�� %d:%d  ����ռ䴴��ʧ�ܡ�\n",1+time[LT_MON],time[LT_MDAY],time[LT_HOUR],time[LT_MIN]));
		return 0;
	}
	else
	{
		make_room_index ++;

		size = sizeof(player);
		for(i=0;i<size;i++)
		{
			player[i]->set_temp("mirror/start_room",start_room);
			call_out("mirror_ok",20,player[i]);
		}
		memory->set("mirror_time",time()+1800); //�������ʱ��
		memory->set("open_time",time());        //����ʼʱ��
		memory->len_exits(); //��ͨ��ͼ(С��)
		memory->heart(1);  //��������
		call_out("make_killer",60,player);   //һ���Ӻ�ʼˢ��
	}
}

void mirror_ok(object me)
{
	object start_room,memory;
	int i,size;
	mapping user_id;

	if(!me) return;

	start_room = (object)me->query_temp("mirror/start_room");
	memory = (object)me->query_temp("mirror/mirror_memory");

	me->enable_player();
	me->delete_temp("block_msg");

	//û�п�ʼ����
	if(!start_room)
	{
		tell_object(me,"���������û�ܽ��뾵��\n");
		user_id = (mapping)memory->query("user_id");
		size = sizeof(user_id);

		for(i=0;i<size;i++)
		{
			if(user_id[sprintf("%d",i)] == me->query("id"))
			{
				memory->set(sprintf("user_id/%d",i),0);
				memory->set(sprintf("user/%d",i),0);
				break;
			}
		}
		return;
	}
	else
	{
		me->move(start_room);
		tell_object(me,HIY"��Χ�������������λӢ������׼����30���ħ�̽�ͽ������֡�\n"NOR); //���
	}
}

varargs void make_killer(object *player,int boss)
{
	int i,size,killer_level=0,all_level=0,all_exp=0,killer_exp=0;
object killer,memory,rand_map,leader;
	mapping maps;
	//tell_object(find_player("rock"),sprintf("debug: player = %O\n",player));
	if(!player) return;

	//ƽ���ȼ�
	size = sizeof(player);
	for(i=0;i<size;i++)
	{
      if(!player[i] || !userp(player[i])) continue;
		all_level += player[i]->query("jym_level/level");
		all_exp += player[i]->query("combat_exp");
if(player[i]->is_team_leader()) leader=player[i];
}
	killer_exp = all_exp/size;
	killer_level = all_level/size;

	memory = (object)player[0]->query_temp("mirror/mirror_memory");
	if(!memory) return; //������

	//������������NPC
	if(!boss) i = MAX_KILLER_INDEX;
	else i = 1;

	while(i--)
	{
                if(memory->query("npc_amount",1) >= 30 ) break;
		
		if(!boss)
		{
			if(killer = new(KILLER_NPC))
			{
				memory->add("npc_amount",1);
				maps = memory->query("maps");
				size = sizeof(maps);
				rand_map = (object)maps[sprintf("%d",random(size))];  //�����ͼ
		
				killer->set("jym_level",killer_level);
				killer->set("combat_exp",killer_exp);

				killer->move(rand_map);
			}
		}
		else
		{
			if(killer = new(BOSS_NPC))
			{
				maps = memory->query("maps");
				size = sizeof(maps);
				rand_map = (object)maps[sprintf("%d",random(size))];  //�����ͼ
		
				killer->set("jym_level",killer_level*(2+random(9)));
				killer->set("combat_exp",killer_exp);

				killer->move(rand_map);
			}
		}
	}
	//tell_object(find_player("rock"),"????\n");
if(!memory->query("send_boss"))
{ 
call_out("make_killer",120,player);    //������Ԯ
if(leader && memory->query("npc_amount",1) < 30)   tell_object(leader,HBMAG"��������һ����Ԯ�ϵ�����ע�ⰲȫ��\n"NOR); }
}


//���� NPC
void del_npc()
{
	object *office;
	int i,size;

	office = children("/quest/gmd/npc/office");

	if(!office) return;

	size = sizeof(office);
	for(i=0;i<size;i++)
	{
		destruct(office[i]);
	}
}
