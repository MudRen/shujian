string *way = ({
        "up",
        "down",
        "west",
        "east",
        "south",
        "north",
        "southeast",
        "southwest",
        "northeast",
        "northwest",
        "southup",
        "southdown",
        "northup",
        "northdown",
        "eastup",
        "eastdown",
        "westup",
        "westdown",
});
        
int valid_leave(object me, string dir)
{
        object ob;
        int i;
        
        if(!environment(me)->query_temp("killed"))
        {
                if (!present("mojiao shashou",environment(me)))
                {
                        if (me->query_temp("hostage/job_1") == 1
                        && !me->query_temp("hostage/passed_x")
                        && random(2)==1)
                        {
                                ob = new(__DIR__"npc/killer1");
                                ob->set_temp("target",me->query("id"));
                                ob->move(environment(me));
                                for(i=0;i<sizeof(way);i++)
                                {
                                        if (dir == way[i] && objectp(present("mojiao shashou", environment(me))))
                                        {
                                                return notify_fail("ħ��ɱ��һ�Ѱ�����ס�������ȵ��������ҳ��ϣ��ȵù�������ء�\n");
                                                break;
                                        }
                                }
                        }
                }
                else
                {
                        for(i=0;i<sizeof(way);i++)
                        {
                                if (dir == way[i] && objectp(present("mojiao shashou", environment(me))))
                                {
                                        return notify_fail("ħ��ɱ��һ�Ѱ�����ס�������ȵ��������ҳ��ϣ��ȵù�������ء�\n");
                                        break;
                                }
                        }
                }
        }
        else if (base_name(environment(me)) == "/d/hmy/midao6" && (dir == "north" || dir == "west"))
        {
                if (me->query_temp("hostage/passed_x") && me->query_temp("hostage"))
                {
                        tell_object(me,"�����ͯ�������˰��죬�ɾ���ת�����ص���\n");
                        tell_object(me,"��ʱ��ֻ��ͯ������ǽ�ڵĽ���������һ�ƣ���Ȼ������һ���Ż���\n");
                        tell_object(me,"���Ǽ�æ�첽���˳�ȥ�����澹Ȼ����������\n");
                        return 1;
                }
                else
                {
                        tell_object(me,"��Ϲ��Ϲײ����Ȼ������������\n");
                        return 1;
                }
        }
        
        return ::valid_leave(me, dir);
}
