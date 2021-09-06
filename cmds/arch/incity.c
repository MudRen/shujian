// ���ӳ����ж� augx@sj

inherit F_CLEAN_UP;

int do_one_room(object room);

int main(object me, string arg)
{
	object room;
	string dir = me->query("cwd");
	
	if(arg) {
		if( !(room=find_object(arg)) )
			if( !(room=find_object(arg+".c")) )
				if( !(room=find_object(dir+arg)) )
					room=find_object(dir+arg+".c");
		if( !room ) {
			tell_object(this_player(),"�Ҳ���Ŀ�귿�䣡\n");
			return 1;
		}
		do_one_room(room);
	}
	else
		do_one_room(environment(me));
        return 1;
}

int do_one_room(object room)
{
	string file;
         
	if (room->query("incity")) {
		tell_object(this_player(),"���б�־�Ѿ��趨���ˡ�\n");
		return 1;
	}
	reset_eval_cost();
	file = read_file(base_name(room)+".c");
	file = replace_string(file,"setup()","set(\"incity\",1);\n	setup()");
		
	if(write_file(base_name(room)+".c",file,1))
		tell_object(this_player(),"���б�־�趨��ɣ�"+ base_name(room) +"\n");
	else
		tell_object(this_player(),"д���б�־����\n");
		
	return 1;
}

