//Death.h By Jpei 2011
//简化死亡处理

void init()
{
	object me = this_player();

        ::init();
     me->delete_temp("no_fight");
     me->clear_condition("was_check");
//这里增加万安寺死亡判断
	if (!userp(me)
	|| me->query("combat_exp") < 10000 && me->query("death_count") > me->query("death_times") * 5) return;
	  if (me->query_temp("special_poison",1))
                call_out("death_stage", 20, me, 0);
        else
                call_out("death_stage", 40, me, 0);

}

void death_stage(object ob, int stage)
{
        if( !ob || !present(ob) ) return;

        if( !ob->is_ghost() ) {
                command("say 轮回无常，阳间之人，应当回到阳间去才是。");
                message_vision("两名力士闪了出来，架起$N，一晃就不见了！\n", ob);
                ob->reincarnate();
                if (ob->query("enter_wuguan")) ob->move(START_ROOM);
                else ob->move(REVIVE_ROOM);
                tell_object(ob, HIW"你一阵晕旋，醒来后却发现自己已经回到了阳间！\n"NOR);
                message("vision","你忽然发现人影不知从什么地方冒了出来。\n", environment(ob), ob);
                return;
        }

	message_vision(death_msg[stage],this_object(),ob);
        if( ++stage < sizeof(death_msg) ) {
                call_out( "death_stage", 5, ob, stage );
                return;
        } else
              ob->reincarnate();
        UPDATE_D->get_cloth(ob);
              ob->delete_temp("special_die");
              ob->setup();       
              ob->set_temp("death_relife",1);
              ob->move(REVIVE_ROOM);

//加一个复活的标记，补满血，给件衣服。然后把人丢出去就完事。在复活点来更新身体好了。
        
message("vision","你忽然发现身旁多了一个人影，不过那人影又好像已经在那里很久了，只是你一直没发觉。\n", REVIVE_ROOM, ob );
}
