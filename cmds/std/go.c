// go.c

inherit F_CLEAN_UP;

mapping default_dirs = ([
	"north":	"北面",
	"south":	"南面",
	"east":		"东面",
	"west":		"西面",
	"northup":      "北边",
	"southup":      "南边",
	"eastup":       "东边",
	"westup":       "西边",
	"northdown":    "北边",
	"southdown":    "南边",
	"eastdown":     "东边",
	"westdown":     "西边",
	"northeast":    "东北",
	"northwest":    "西北",
	"southeast":    "东南",
	"southwest":    "西南",
	"up":	   "上面",
	"down":	 "下面",
	"enter":	"里面",
	"out":	  "外面",
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

	if (!arg ) return notify_fail("你要往哪个方向走？\n");
	
	if(arg=="away") {
		if(!me->is_fighting()) return notify_fail("你又不在战斗中跑什么跑？\n");
		do_flee(me);
		return 1;
	}
		
	if (me->query_temp("on_baitan") )
		return notify_fail("你正在摆摊，起身不得。\n");
		
        if (me->over_encumbranced() && userp(me) )
		return notify_fail("你的负荷过重，动弹不得。\n");

	if (me->is_busy() )
		return notify_fail("你的动作还没有完成，不能移动。\n");
	env = environment(me);
	if (me->is_fighting()) {
		f_obs = me->query_enemy();
		if (objectp(f_obs[0]) && living(f_obs[0]))
		if (env == environment(f_obs[0]) && 2 + random((int)me->query_dex()) <= 
			random((int)f_obs[0]->query_dex())) {
			me->start_busy(1);
			if(f_obs[0]->query("race") != "人类")
			       message_vision("$N转身想跑，被$n猛地一下扑上来，拦住去路！\n", me, f_obs[0]);
			else message_vision("$N转身就要开溜，被$n一把拦住！\n", me, f_obs[0]);
			return notify_fail("你逃跑失败。\n");
		}
	}

	if (!env) return notify_fail("你哪里也去不了。\n");

	dest = env->query("exits/"+arg);
	if (!dest) {
		if (query_verb()=="go") notify_fail("这个方向没有出路。\n");
		return 0;
	}
        dirs = env->query("exits");
        if (!mapp(dirs) || !(dest = dirs[arg])) {
                if (query_verb()=="go") notify_fail("这个方向没有出路。\n");
                return 0;
        }

	obj = load_object(dest);
	if (!obj) return notify_fail("这个方向无法移动，请报告巫师。\n");

	if (!env->valid_leave(me, arg) ) {
		if (this_player() == me) write(query_notify_fail());
		return 1;
	}

	if (env->query("outdoors")) cost = 1 + random(me->query_encumbrance() / 20000);
	cost += env->query("jingli_cost/"+arg);
	if (NATURE_D->is_night()) cost *= 2;
	if (userp(me) && !wizardp(me) && me->query("jingli") < cost)
		return notify_fail("你太累了，休息一下再走吧。\n");

	dir = obj->query("short");
	
	if (obj->query("daytime_only") && NATURE_D->is_night()){
		if(stringp(min = obj->query("daytime_only"))) return notify_fail(min);
		return notify_fail(dir+"已经关门了，你等天亮了再来吧！\n");
	}

	if (!undefinedp(default_dirs[arg]))
		dir = default_dirs[arg] + "的" + dir;

	if (me->is_fighting() && !me->clean_up_enemy() && me->is_fighting()) {
		mout = "往" + dir + "落荒而逃了。\n";
		min = "从" + env->query("short") + "跌跌撞撞地跑了过来，模样有些狼狈。\n";
	} else {
		min = mout = me->query_condition("killer")?
			"神色慌张地":"";
		mout += "往" + dir + "离开。\n";
		switch(me->query("race")) {
			case "人类":
				min += "从" + env->query("short") + "走了过来。\n";
				break;
			default:
				min = "从" + env->query("short") + "蹿了过来。\n";
		}
	}

        if (me->query_condition("no_force")) me->start_busy(1);

//--------从这里开始。修改一下进入和离开的描述，对队员，没有设置屏蔽的，我不在战斗（落荒而逃是应该看得见的），我不是userp(npc的走动应该任何人都可以看得见。)------------------------
if (me->move(obj) ) {


obl = all_inventory(env);   

 if(obl) {
  if(me->query_team()) { foreach (ob in obl )

         {                 
                     if( member_array(ob,me->query_team())!=-1 //队员（显示或者不显示）
                      || !ob->query("env/brf_go")           //设置了显示
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
                     if( (member_array(ob,me->query_team())!=-1 //队员（显示或者不显示）
                      || !ob->query("env/brf_go")           //设置了显示
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
	tell_object(me, "看来该找机会逃跑了...\n");
	main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
	write(@HELP
指令格式 : go <方向>
 
让你往指定的方向移动。
 
HELP
    );
    return 1;
}
