//Modifyed BY LinuX@SJ ������ɫ��ʾ
// Modified by Ciwei@SJ �Ż�
/*
help map xxxx    ��ʾ/help/map/�µ��ļ� xxxx ��Ӧ�ļ���
help job xxxx    ��ʾ/help/job/�µ��ļ� xxxx ��Ӧ�ļ���
help group xxxx  ��ʾ/help/group/�µ��ļ� xxxx ��Ӧ�ļ���
help dazao xxxx  ��ʾ/help/dazao/�µ��ļ� xxxx ��Ӧ�ļ���
help quest xxxx  ��ʾ/help/quest/�µ��ļ� xxxx ��Ӧ�ļ���
help party xxxx  ��ʾ/help/party/�µ��ļ� xxxx ��Ӧ�ļ���
help xxxx        ��ʾ/help/topic/ ���� /help/misc/�µĶ�
		 Ӧ xxxx ��Ӧ�ļ��������ȿ���/topic/

*/
inherit F_CLEAN_UP;
#include <ansi.h>
#include <mudlib.h>
#include "/doc/help.h"

private int show_the_help(object me,string file);
private string color_filter(string content);
private string get_title(string str);
string *default_search = DEFAULT_SEARCH_PATHS;

int main(object me, string arg )
{
        int i;
        string file, *search, dir;

        if( !arg ) 
        {
                if(show_the_help(me,HELP_DIR + "topics")) return 1;
                error("help topics ���Ƿ��ƶ���");
                return 1;
                //write(color_filter(read_file(HELP_DIR + "topics")));
                //return 1;
        }
        
        seteuid( getuid() );
        if( sscanf(arg, "map %s", arg) ) 
        {
                if( file_size("/help/map/"+arg) > 0 ){
                	if(show_the_help(me,"/help/map/" + arg)) return 1;
                //me->start_more(color_filter( read_file("/help/map/" + arg) ));
                //return 1;	
                }
                else
                	return notify_fail("Ŀǰ��û�� "+HIY+arg+NOR+ " �����ͼ�����ļ���\n");          
          
        } 
        
        
        if( sscanf(arg, "quest %s", arg) ) 
        {
                if( file_size("/help/quest/"+arg) > 0 ){
                	if(show_the_help(me,"/help/quest/" + arg)) return 1;
                //me->start_more(color_filter( read_file("/help/quest/" + arg) ));
                //return 1;	
                }
                else
                	return notify_fail("Ŀǰ��û�� "+HIY+arg+NOR+ " ����������ܰ����ļ���\n");          
          
        } 
        
        if( sscanf(arg, "group %s", arg) ) 
        {
                if( file_size("/help/group/"+arg) > 0 ){
                	if(show_the_help(me,"/help/group/" + arg)) return 1;
                //me->start_more(color_filter( read_file("/help/group/" + arg) ));
                //return 1;	
                }
                else
                	return notify_fail("Ŀǰ��û�� "+HIY+arg+NOR+ " ������ɰ����ļ���\n");  
        } 
        
        if( sscanf(arg, "dazao %s", arg) ) 
        {
                if( file_size("/help/dazao/"+arg) > 0 ){
                	if(show_the_help(me,"/help/dazao/" + arg)) return 1;
                //me->start_more(color_filter( read_file("/help/dazao/" + arg) ));
                //return 1;	
                }
                else
                	return notify_fail("Ŀǰ��û�� "+HIY+arg+NOR+ " �������ϵͳ�����ļ���\n");  
        } 
        /*
        if( sscanf(arg, "career %s", arg) ) 
        {
                if( file_size("/help/career/"+arg) > 0 ){
                me->start_more(color_filter( read_file("/help/career/" + arg) ));
                return 1;	
                }
                else
                	return notify_fail("Ŀǰ��û�� "+HIY+arg+NOR+ " ���ְҵϵͳ�����ļ���\n");
                
                
          
        } */
        
	if( sscanf(arg, "job %s", arg) ) 
        {
                dir = "/help/job/";
                if( file_size("/help/job/"+arg) > 0 ){
                	if(show_the_help(me,"/help/job/" + arg)) return 1;
                //me->start_more(color_filter( read_file("/help/job/" + arg) ));
                //return 1;
       		 }
       		else
       			 return notify_fail("Ŀǰ��û�� "+HIY+arg+NOR+" �������������������û�а����ļ���\n");
        }
		
	if( sscanf(arg, "party %s", arg) ) 
        {
                dir = "/help/party/";
                if( file_size("/help/party/"+arg) > -1 ){                	
                	if(show_the_help(me,"/help/party/" + arg)) return 1;
                //me->start_more(color_filter( read_file("/help/party/" + arg) ));
                //return 1;
        	}
        	else
        	return notify_fail("Ŀǰ��û�� "+HIY+arg+NOR+" ������ɵ����ϡ�\n");
        } 

        arg = ALIAS_D->process_global_alias( arg );
        if( stringp( file = me->find_command( arg )) ) 
        {
                notify_fail("�����ָ����ڣ���û��˵���ļ���\n");
                return write( HIG"��"HIW+CHINESE_MUD_NAME+HIG" ��"NOR"\n") + file->help( me );
        }

        if( pointerp( search = me->query( "help_search_path" ) ) ) 
        {
                i = sizeof(search);
                while( i-- )
                {
                        if( file_size( search[i] + arg) > 0 ) 
                        {
                                if(show_the_help(me,search[i] + arg)) return 1;
                        }
                }
        }

        sscanf(arg, "%s()", arg);
        if( pointerp(default_search) ) 
        {
                i = sizeof(default_search);
                while(i--) 
                {
                        if( file_size(default_search[i] + arg)>0 ) 
                        {
				if(show_the_help(me,default_search[i] + arg)) return 1;
                        }
                }
        }

        return notify_fail("û����� "HIY+arg+NOR" ���������˵���ļ���\n");
}
private int show_the_help(object me,string file)
{
	if(file_size(file)<0) return 0;
	if (me->query("env/fastread"))
		if (file_size(file) > 8192 )
		{
			tell_object(me,
                	HIY"�ܱ�Ǹ����Ϊ�������ĵ��ļ��Ƚϴ�ֻ��һҳҳ��ʾ��\n"NOR);
			me->start_more( color_filter( read_file(file) ) );
		}
		else write(color_filter( read_file(file) ));
	else me->start_more( color_filter( read_file(file) ) );
	return 1;
}

private string color_filter(string msg)
{
        string *output;
        int i;
        string content = "";
        if (! msg)
                return "";
	
	output = explode(msg,"\n");
	
	for(i=0;i<sizeof(output);i++)
	{
		if(strsrch(output[i],"$TITLE$") < 0)
		{
			content += (output[i] + "\n"); 
			continue;
		}
		else
		{
			output[i]= replace_string(output[i],"$TITLE$","");
			content += replace_string(output[i],output[i],get_title(output[i]));
		}
	}

        /*  Foreground Colors  */

	content = replace_string(content, "$BLK$", BLK);		/* Black   */
	content = replace_string(content, "$RED$", RED);		/* Red     */
	content = replace_string(content, "$GRN$", GRN);		/* Green   */
	content = replace_string(content, "$YEL$", YEL);		/* Yellow  */
	content = replace_string(content, "$BLU$", BLU);		/* Blue    */
	content = replace_string(content, "$MAG$", MAG);		/* Magenta */
	content = replace_string(content, "$CYN$", CYN);		/* Cyan    */
	content = replace_string(content, "$WHT$", WHT);		/* White   */

	/*  Hi Intensity Foreground Colors  */

	content = replace_string(content, "$HIR$", HIR);		/* Red     */
	content = replace_string(content, "$HIG$", HIG);		/* Green   */
	content = replace_string(content, "$HIY$", HIY);		/* Yellow  */
	content = replace_string(content, "$HIB$", HIB);		/* Blue    */
	content = replace_string(content, "$HIM$", HIM);		/* Magenta */
	content = replace_string(content, "$HIC$", HIC);		/* Cyan    */
	content = replace_string(content, "$HIW$", HIW);		/* White   */

        /*  Background Colors  */

	content = replace_string(content, "$BBLK$", BBLK);		/* Black   */
	content = replace_string(content, "$BRED$", BRED);		/* Red     */
	content = replace_string(content, "$BGRN$", BGRN);		/* Green   */
	content = replace_string(content, "$BYEL$", BYEL);		/* Yellow  */
	content = replace_string(content, "$BBLU$", BBLU);		/* Blue    */
	content = replace_string(content, "$BMAG$", BMAG);		/* Magenta */
	content = replace_string(content, "$BCYN$", BCYN);		/* Cyan    */

	/*  Hi Intensity Background Colors  */

	content = replace_string(content, "$HBRED$", HBRED);	/* Red     */
	content = replace_string(content, "$HBGRN$", HBGRN);	/* Green   */
	content = replace_string(content, "$HBYEL$", HBYEL);	/* Yellow  */
	content = replace_string(content, "$HBBLU$", HBBLU);	/* Blue    */
	content = replace_string(content, "$HBMAG$", HBMAG);	/* Magenta */
	content = replace_string(content, "$HBCYN$", HBCYN);	/* Cyan    */

	content = replace_string(content, "$NOR$", NOR);	/* Puts everything back to normal */

	/*  Additional  */

	content = replace_string(content, "$U$", U);		/* Initialize underscore mode */		
	content = replace_string(content, "$BLINK$", BLINK);	/* Initialize blink mode */
	content = replace_string(content, "$REV$", REV);	/* Turns reverse video mode on */
	content = replace_string(content, "$HIREV$", HIREV);	/* Hi intensity reverse video  */
	content = replace_string(content, "$BOLD$", BOLD);	/* Turn on bold mode */

        return content;
}
string get_title(string str)
{
        string arg;
	arg = sprintf("$BBLU$$HIW$%|60s$NOR$\n",str);
        return arg;
} 

int help(object me)
{
        write(@HELP
----------------------------------------
ָ���ʽ��help <����>

help <��������>
      
���磺> help cmds

���ָ���ṩ�����ĳһ�������ϸ˵���ļ������ǲ�ָ�����⣬
���ṩ���й�������ļ���

/*help map
�鿴��ͼ

help group <��������>
�鿴���ɼ��*/
----------------------------------------
HELP
        );
        return 1;
}
