// go.c

inherit F_CLEAN_UP;

mapping default_dirs = ([
	"north":	"����",
	"south":	"����",
	"east":		"����",
	"west":		"����",
	"northup":      "����",
	"southup":      "�ϱ�",
	"eastup":       "����",
	"westup":       "����",
	"northdown":    "����",
	"southdown":    "�ϱ�",
	"eastdown":     "����",
	"westdown":     "����",
	"northeast":    "����",
	"northwest":    "����",
	"southeast":    "����",
	"southwest":    "����",
	"up":	   "����",
	"down":	 "����",
	"enter":	"����",
	"out":	  "����",
]);

int night = 0;

void do_flee(object me);

int night_time(int i)
{
    night = i;
    return night;
}

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string dest, mout, min, dir;
	int cost,i;
	object env, obj, ob;
	object *f_obs;
	object *obl;
	mapping dirs;

	if (!arg ) return notify_fail("��Ҫ���ĸ������ߣ�\n");
	
	if(arg=="away") {
		if(!me->is_fighting()) return notify_fail("���ֲ���ս������ʲô�ܣ�\n");
		do_flee(me);
		return 1;
	}
		
	if (me->query_temp("on_baitan") )
		return notify_fail("�����ڰ�̯�������á�\n");
		
        if (me->over_encumbranced() && userp(me) )
		return notify_fail("��ĸ��ɹ��أ��������á�\n");

	if (me->is_busy() )
		return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
	env = environment(me);
	if (me->is_fighting()) {
		f_obs = me->query_enemy();
		if (objectp(f_obs[0]) && living(f_obs[0]))
		if (env == environment(f_obs[0]) && 2 + random((int)me->query_dex()) <= 
			random((int)f_obs[0]->query_dex())) {
			me->start_busy(1);
			if(f_obs[0]->query("race") != "����")
			       message_vision("$Nת�����ܣ���$n�͵�һ������������סȥ·��\n", me, f_obs[0]);
			else message_vision("$Nת���Ҫ�����$nһ����ס��\n", me, f_obs[0]);
			return notify_fail("������ʧ�ܡ�\n");
		}
	}

	if (!env) return notify_fail("������Ҳȥ���ˡ�\n");

	dest = env->query("exits/"+arg);
	if (!dest) {
		if (query_verb()=="go") notify_fail("�������û�г�·��\n");
		return 0;
	}
        dirs = env->query("exits");
        if (!mapp(dirs) || !(dest = dirs[arg])) {
                if (query_verb()=="go") notify_fail("�������û�г�·��\n");
                return 0;
        }

	obj = load_object(dest);
	if (!obj) return notify_fail("��������޷��ƶ����뱨����ʦ��\n");

	if (!env->valid_leave(me, arg) ) {
		if (this_player() == me) write(query_notify_fail());
		return 1;
	}

	if (env->query("outdoors")) cost = 1 + random(me->query_encumbrance() / 20000);
	cost += env->query("jingli_cost/"+arg);
	if (NATURE_D->is_night()) cost *= 2;
	if (userp(me) && !wizardp(me) && me->query("jingli") < cost)
		return notify_fail("��̫���ˣ���Ϣһ�����߰ɡ�\n");

	dir = obj->query("short");
	
	if (obj->query("daytime_only") && NATURE_D->is_night()){
		if(stringp(min = obj->query("daytime_only"))) return notify_fail(min);
		return notify_fail(dir+"�Ѿ������ˣ���������������ɣ�\n");
	}

	if (!undefinedp(default_dirs[arg]))
		dir = default_dirs[arg] + "��" + dir;

	if (me->is_fighting() && !me->clean_up_enemy() && me->is_fighting()) {
		mout = "��" + dir + "��Ķ����ˡ�\n";
		min = "��" + env->query("short") + "����ײײ�����˹�����ģ����Щ�Ǳ���\n";
	} else {
		min = mout = me->query_condition("killer")?
			"��ɫ���ŵ�":"";
		mout += "��" + dir + "�뿪��\n";
		switch(me->query("race")) {
			case "����":
				min += "��" + env->query("short") + "���˹�����\n";
				break;
			default:
				min = "��" + env->query("short") + "���˹�����\n";
		}
	}

        if (me->query_condition("no_force")) me->start_busy(1);

//--------�����￪ʼ���޸�һ�½�����뿪���������Զ�Ա��û���������εģ��Ҳ���ս������Ķ�����Ӧ�ÿ��ü��ģ����Ҳ���userp(npc���߶�Ӧ���κ��˶����Կ��ü���)------------------------
if (me->move(obj) ) {


obl = all_inventory(env);   

 if(obl) {
  if(me->query_team()) { foreach (ob in obl )

         {                 
                     if( member_array(ob,me->query_team())!=-1 //��Ա����ʾ���߲���ʾ��
                      || !ob->query("env/brf_go")           //��������ʾ
                      || me->is_fighting() || !userp(me) && ob!=me  )    
         tell_object(ob, me->name() + mout);
          }
                        }
 else  foreach (ob in obl )
       {
          if(!ob->query("env/brf_go") || me->is_fighting() || !userp(me) && ob!=me )
               tell_object(ob, me->name() + mout);
       }
         }



obl = all_inventory(obj);
 
 if(obl) {
  if(me->query_team()) { foreach (ob in obl )

         {                 
                     if( (member_array(ob,me->query_team())!=-1 //��Ա����ʾ���߲���ʾ��
                      || !ob->query("env/brf_go")           //��������ʾ
                      || me->is_fighting() || !userp(me)) && ob!=me )    
         tell_object(ob, me->name() + min);
          }
                        }
 else  foreach (ob in obl )
       {
          if((!ob->query("env/brf_go") || me->is_fighting() || !userp(me)) && ob!=me )
               tell_object(ob, me->name() + min);
       }
         }

//---------------------------------------------------
		me->delete_temp("pending");
		all_inventory(env)->follow_me(me, arg);
		if (!userp(me)) {
			if (stringp(dest = me->query("startroom")) && !me->query("location")) {
				if (random(me->query_temp("random_move")) > 15)

					me->return_home(dest);
			}
		}
		return 1;
	}
	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if (!environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if (!mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	tell_object(me, "�������һ���������...\n");
	main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
	write(@HELP
ָ���ʽ : go <����>
 
������ָ���ķ����ƶ���
 
HELP
    );
    return 1;
}
