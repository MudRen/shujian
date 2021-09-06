// wh_poison.c

#include <ansi.h>
	
int update_condition(object me, int duration)
{
	int i,j;
	string dutype;
	object * ob,* inv,obj;
	mapping exits;
	string *directions;
	string roomf,dis,oroom;
	string* luanyu=({"...","????"});
	mapping dirs = ([
	"north":		"����",
	"south":		"����",
	"east":			"����",
	"west":			"����",
	"northup":		"����",
	"southup":		"�ϱ�",
	"eastup":		"����",
	"westup":		"����",
	"northdown":	"����",
	"southdown":	"�ϱ�",
	"eastdown":		"����",
	"westdown":		"����",
	"northeast":	"����",
	"northwest":	"����",
	"southeast":	"����",
	"southwest":	"����",
	"up":			"����",
	"down":			"����",
	"enter":		"����",
	"out":			"����"
	]);

	if(!me)
		return 0;
	if(duration<1)
	{
		me->delete("poisontype");
		me->delete_temp("no_fight");
		if(objectp(me->query_temp("huanjue",1)))
		{
			destruct(me->query_temp("huanjue",1));
		}
		me->delete_temp("huanjue");
		me->delete_temp("block_msg/sound");
		me->delete_temp("block_msg/emote");
                return 0;
	}
	if(me->is_ghost())
        {
         	me->delete("poisontype");
		me->delete_temp("no_fight");
		if(objectp(me->query_temp("huanjue",1)))
		{
			destruct(me->query_temp("huanjue",1));
		}
		me->delete_temp("huanjue");
		me->delete_temp("block_msg/sound");
		me->delete_temp("block_msg/emote");
                return 0;
        }
	dutype=me->query("poisontype");
	if(dutype!="ˮ")
	{
		if(objectp(me->query_temp("huanjue",1)))
		{
			destruct(me->query_temp("huanjue",1));
		}
		me->delete_temp("huanjue");
		me->delete_temp("block_msg/sound");
		me->delete_temp("block_msg/emote");
	}
	switch(dutype)
	{
		case "��"://ɱ��
			tell_object(me,HIR"��е�ͻȻ��һ��ɱ������ͷð����\n"NOR);
			ob = all_inventory(environment(me));
           		for(i=0; i<sizeof(ob); i++) 
			{
				if(!living(ob[i])) 
					continue;
				if(ob[i]->is_fighting(me))
					continue;
				if(me->query("combat_exp")>ob[i]->query("combat_exp"))
					continue;
				me->kill_ob(ob[i]);
				ob[i]->kill_ob(me);
			}
			if(!me->is_fighting())
			{
				if(me->query("neili")>=100)
				{
					tell_object(me,"��æ������ѹ�����е�ɱ����\n");
					me->add("neili",-100);
				}
				else if(me->query("qi")>me->query("max_qi")/20)
				{
					tell_object(me,"ȴ�޴����Է�й��ֻ�����صش����Լ�������һȭ������һ����Ѫ������\n");
					me->add("qi",-me->query("max_qi")/50);
				}
				else
					tell_object(me,"����������Ѫ���㣬������ʵ��ɡ�\n");	
			}
			break;
		case "ľ"://η��
			tell_object(me,HIR"��ͻȻ�е���ֿ־壬ֻ���Ҹ��ط���������\n"NOR);
			if(me->query("shen")>0)
			{
				me->add("shen",-(1000+random(501)));
				if(me->query("shen")<0)
					me->set("shen",0);
			}
			else if(me->query("shen")<0)
			{
				me->add("shen",1000+random(501));
				if(me->query("shen")>0)
					me->set("shen",0);
			}
			me->set_temp("no_fight",1);
			break;
		case "ˮ"://�þ�
			if(!me->query_temp("huanjue",1))
			{
				obj=new("/d/sld/npc/obj/huanjue");
				if(!obj)
					break;
				if(obj->move(me))
					me->set_temp("huanjue",obj);
				else
				{
					me->set("poisontype","ľ");
					destruct(obj);
					break;
				}
			}
			else
			{
				obj=me->query_temp("huanjue",1);
				if(!objectp(obj) || (me!=environment(obj)))
				{
					if(objectp(obj))
						destruct(obj);
					me->delete_temp("huanjue");
					obj=new("/d/sld/npc/obj/huanjue");
					if(!obj)
						break;
					if(obj->move(me))
						me->set_temp("huanjue",obj);
					else
					{
						me->set("poisontype","ľ");
						destruct(obj);
						break;
					}
				}
			}
			me->set_temp("block_msg/sound",1);
			me->set_temp("block_msg/emote",1);
			tell_object(me,HIR"���������Ի�֮�У�\n"NOR);
			break;
		case "��"://��
			tell_object(me,HIR"��ͻȻ�е�ȫ�������ޱȣ�\n"NOR);
			ob = all_inventory(me);
			for(i=0;i<sizeof(ob);i++)
			{
				if(ob[i]->query("no_drop"))
					continue;
				inv = all_inventory(environment(me));  
        			if(sizeof(inv)>49)
				{
					if(!ob[i]->is_character())
            					destruct(ob[i]);
				}
				else if(ob[i]->move(environment(me)))
				{
            				if(ob[i]->is_character() )
                				message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, ob[i]);
            				else 
					{
                				message_vision(sprintf("$N����һ%s$n��\n",ob[i]->query("unit")),me,ob[i]);
                                        }
            			}
        		}
			if(me->query("jingli")>100)
				me->add("jingli",-100);
			else
				me->set("jingli",1);
			break;
		case "��"://����
			tell_object(me,HIR"��ͻȻ�е�ͷ��һƬ���ң����ǲ��壡\n"NOR);
			switch(random(3))
			{
				case 0: //random move
					if( environment(me) && living(me))
					{
						exits = environment(me)->query("exits");
						if( mapp(exits) && sizeof(exits))
						{
							directions = keys(exits);
							dis=directions[random(sizeof(directions))];
							roomf=exits[dis];
							if(objectp(find_object(roomf)) || objectp(load_object(roomf)))
							{
								oroom=environment(me)->name(1);
								message_vision(sprintf("$N��%s�뿪�ˡ�\n",dirs[dis]),me);
								me->move(roomf);
								message_vision(sprintf("$N��%s�߹�����\n",oroom),me);
								break;
							}
						}
					}
				case 1: //give 
					ob = all_inventory(environment(me));
					inv = all_inventory(me);
					if(sizeof(ob)>1 && sizeof(inv)>0)
					{
						i=random(sizeof(inv));
						j=i;
						while(inv[i]->query("no_drop") || inv[i]->query("no_give"))
						{
							i=i+1;
							if(i==sizeof(inv))
								i=0;
							if(i==j)
								break;
						}
						if(!inv[i]->query("no_drop") && !inv[i]->query("no_give"))
						{
							for(j=0;j<sizeof(ob);j++)
							{
								if(me==ob[j])
									continue;
								if(living(ob[j]) && inv[i]->move(ob[j]))
								{
									message_vision(sprintf("$N��%s����$n��\n",inv[i]->name(1)),me,ob[j]);
									break;
								}
							}
							if(j<sizeof(ob))
								break;
						}
					}
				default://random say
					message_vision(luanyu[random(sizeof(luanyu))],me);
					break;
			}	
			break;
		default:
			break;
	}
	me->set_temp("last_damage_from", "��������"+dutype+"������");
	message_vision(BLU "$N���е���������"+dutype+"�������ˣ�\n" NOR, me);
	me->apply_condition("wh_poison", duration-1);
	
	return 1;
}

string query_type(object me)
{
        return "poison";
}