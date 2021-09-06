void init()
{
	object me = this_player();

        ::init();
     me->delete_temp("no_fight");
	if (!userp(me)
	|| me->query("combat_exp") < 10000 && me->query("death_count") > me->query("death_times") * 5) return;
	  if (me->query_temp("special_poison",1))
                call_out("death_stage", 20, me, 0);
        else
                call_out("death_stage", 40, me, 0);

}

void death_stage(object ob, int stage)
{
//        int i;
        object *inv;
        if( !ob || !present(ob) ) return;

        if( !ob->is_ghost() ) {
                command("say �ֻ��޳�������֮�ˣ�Ӧ���ص�����ȥ���ǡ�");
                message_vision("������ʿ���˳���������$N��һ�ξͲ����ˣ�\n", ob);
                ob->reincarnate();
                if (ob->query("enter_wuguan")) ob->move(START_ROOM);
                else ob->move(REVIVE_ROOM);
                tell_object(ob, HIW"��һ��������������ȴ�����Լ��Ѿ��ص������䣡\n"NOR);
                message("vision","���Ȼ������Ӱ��֪��ʲô�ط�ð�˳�����\n", environment(ob), ob);
                return;
        }

	message_vision(death_msg[stage],this_object(),ob);
        if( ++stage < sizeof(death_msg) ) {
                call_out( "death_stage", 5, ob, stage );
                return;
        } else
                ob->reincarnate();

        inv = all_inventory(ob);
/*        if(!ob->query_temp("special_die")){
        for (i = 0; i < sizeof(inv); i++)
                DROP_CMD->do_drop(ob, inv[i]);

        UPDATE_D->get_cloth(ob);
        }
*/
    if (ob->query_temp("special_die")){
        ob->delete_temp("special_die");
        ob->delete_temp("kill_other");
        ob->delete_temp("other_kill");
       }

        if (ob->query("enter_wuguan")) ob->move(START_ROOM);
        else ob->move(REVIVE_ROOM);
ob->setup();
        message("vision","���Ȼ�������Զ���һ����Ӱ����������Ӱ�ֺ����Ѿ�������ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);
}
