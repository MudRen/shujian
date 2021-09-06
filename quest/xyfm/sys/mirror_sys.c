//edit by rock
//2008.10.16
//���ļ����ᱻ��¡

#include <ansi.h>
#include <localtime.h>
#include "/quest/xyfm/sys/list.h"

#define MAX_ROOM_INDEX 20
#define OFFICE_NPC     "/quest/xyfm/npc/office"
#define MIRROR_MEMORY  "/quest/xyfm/sys/memory"
#define KILLER_NPC     "/quest/xyfm/npc/jiangshi"
#define BOSS_NPC       "/quest/xyfm/npc/boss"
#define MAX_KILLER_INDEX 200

//ȫ�ֱ���
int make_room_index;
int ob_time;

//��������
void check_time();
int mirror(object player);
void del_npc();
void mirror_ok(object me);
varargs void make_killer(object *player,int boss);

//��������ѯ��������������
int query_room_amount() { return make_room_index; }
/*
//��ʼ��
void create() { check_time(); }

//���ʱ��
void check_time()
{
	object npc;

	if(!ob_time)
	{
		//2Сʱһ��
		ob_time = time()+2*3600;
	}
//tell_object(find_player("rock"),"\nʱ��.......\n");
	if(ob_time <= time())
	{
		//�ͨ��
		//��¡NPC
		npc = new(OFFICE_NPC);
		if(npc)
		{
			CHANNEL_D->do_channel( npc, "chat", "������ħ�����Ѿ��򿪣�����λӢ��ǰ��һ̽������\n");
			//�ŵ� /d/city/wumiao
			npc->move("/d/city/wumiao");
			//���������������
			make_room_index = 0;
			//��������NPC(10����)
			call_out("del_npc",600);
			//����ʱ��
			ob_time = time()+2*3600;
		}
	}
	//ʱ��û���ͼ���ѭ��
	if((time() + 1800) >= ob_time)
	{
		call_out("check_time",600);
	}
	else if((time() + 600) >= ob_time)
	{
		call_out("check_time",60);
	}
	else call_out("check_time",1800);
}
*/
//NPC���ã����쾵������
int mirror(object player)
{


object maps,memory,start_room;
	int i,size,j,index;
	mixed time;
	string fileName;

	if(!player /*|| make_room_index >= MAX_ROOM_INDEX*/ ) return 0;

	//�����ڴ�
	if(!memory = new(MIRROR_MEMORY)) return 0;

	memory->set(sprintf("user_id/%d",i),player->query("id"));
		memory->set(sprintf("user/%d",i),player);
		player->set_temp("mirror/mirror_memory",memory);
tell_object(player,WHT"ս�����𣬸�ʬ��Ұ������������ʱ������֮��,\n"+
             "���ķ����˼��н�ʬԹ�����������ͼ������£�\n"+
             "���̸����µ�����ʦ̽���������٣���Ѱ��ʿ������\n"+             
             "�ܷ�Ҵ��������࣬�����������Ǭ�����Ϳ�����ˣ�\n\n"NOR);

             tell_object(player,HIG"����ʾ��������ʬ���غ��£�ֻ����ǰ����������̽�����ࡣ\n"NOR);
             tell_object(player,HIG"����ʾ��������ʱ���Զ��رգ�������д��ͻسǣ����ص��ġ�\n\n"NOR);

	tell_object(player,HIR"��������ħ������Ϊ�����콵����ħ���������Ժ�......\n"NOR);
	player->disable_player("<���뾵����>");
	player->set_temp("block_msg/all",1);

	//��������
	size = sizeof(mirror_maps);
	for(j=0;j<size;j++)
	{
		maps = new(mirror_maps[j]);
if(maps)
		{
			//���е�ͼ��memory
			memory->set(sprintf("maps/%d",j),maps);
			sscanf(mirror_maps[j],"/quest/xyfm/%s",fileName);
			memory->set(fileName,maps);
			maps->set("memory",memory);
			if(maps->query("short") == "Ұ��ƽ��")
			{
				start_room = maps;
			}
			index ++;
		}
	}

if(index < 1 || !start_room)
	{
		size = sizeof(player);
		for(i=0;i<size;i++)
		{
			player->enable_player();
			player->delete_temp("block_msg");
			tell_object(player,"Error: ��������ʧ�ܣ�����ϵ��ʦ��\n");
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

		
			player->set_temp("mirror/start_room",start_room);
			call_out("mirror_ok",20,player);
		
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
		tell_object(me,HIR"��������ħ��������׼����30������Թ�����֡�\n"NOR); //���
	}
}

varargs void make_killer(object player,int boss)
{
	int i,size,killer_level=0,all_level=0,all_exp=0,killer_exp=0;
	object killer,memory,rand_map;
	mapping maps;

	if(!player) return;

	memory = (object)player->query_temp("mirror/mirror_memory");
	if(!memory) return; //������
	//������������NPC
	if(!boss) i = MAX_KILLER_INDEX;
	else i = 1;

	while(i--)
	{
		if(memory->query("npc_amount",1) >= 201 ) break;	
if(!boss)
		{
			if(killer = new(KILLER_NPC))
			{
				memory->add("npc_amount",1);
				maps = memory->query("maps");
				size = sizeof(maps);
				rand_map = (object)maps[sprintf("%d",random(size))];  //�����ͼ

				killer->move(rand_map);
			}
		}
		else
		{
if(killer = new(BOSS_NPC))
			{
				memory->add("npc_amount",1);
				maps = memory->query("maps");
				rand_map = (object)maps[sprintf("%d",random(size))];  //�����ͼ

				killer->move(rand_map);
			}
		}
	}
}
//���� NPC
void del_npc()
{
	object *office;
	int i,size;

	office = children("/quest/xyfm/npc/office");

	if(!office) return;

	size = sizeof(office);
	for(i=0;i<size;i++)
	{
		destruct(office[i]);
	}
}
