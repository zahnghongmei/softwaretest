vuser_end()
{
strcpy(t_result,"</table></html>");

fputs(t_result,file);

fclose(file);

	return 0;
}
